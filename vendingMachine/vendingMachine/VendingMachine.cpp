//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   VendingMachine.cpp
//!
//! @brief  �����̔��@�N���X�̃\�[�X�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//�C���N���[�h
#include <iostream>
#include "VendingMachine.h"
#include "OrangeJuice.h"
#include "Cola.h"
#include "Utility.h"

//�萔
#pragma region Constant
//�d�݂̍݌ɖ���
const int VendingMachine::sCOINSTOCK_NUM = 20;
//���ݕ��̍݌ɖ{��
const int VendingMachine::sDRINKSTOCK_NUM = 10;
//�R�[���̒l�i
const int VendingMachine::sCOLA_PRICE = 120;
//�I�����W�W���[�X�̒l�i
const int VendingMachine::sORANGE_PRICE = 100;
#pragma endregion

//���O���
using namespace std;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
VendingMachine::VendingMachine()
{
}

//----------------------------------------------------------------------
//! @brief �����ݒ�
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void VendingMachine::Initialize()
{
	//�d�݂̍݌ɂ����߂�
	m_moneyNum = make_unique<Money>();
	//1000�~�D�͏o�Ȃ�
	for (int i = Money::BILL1000; i < Money::MONEYTYPE_NUM; i++)
	{
		m_moneyNum->AddMoney(i, sCOINSTOCK_NUM);
	}
	//���ݕ��̍݌ɂ����߂�
	for (int i = 0; i < DRINKTYPE_NUM; i++)
	{
		m_drinkStock[i] = sDRINKSTOCK_NUM;
	}
	m_receivedMoney = make_unique<Money>();
	m_changeMoney = make_unique<Money>();
	//�R�[��
	std::unique_ptr<CDrink> cola = std::make_unique<Cola>(sCOLA_PRICE);
	m_drink.push_back(move(cola));
	//�I�����W�W���[�X
	std::unique_ptr<CDrink> orangeJuice = std::make_unique<OrangeJuice>(sORANGE_PRICE);
	m_drink.push_back(move(orangeJuice));
}

//----------------------------------------------------------------------
//! @brief �̔����Ă�����̂̎�ނ�\��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void VendingMachine::ShowAllKind()
{
	Utility::DrawCharaNewLine("�����Ă��镨�̈ꗗ�ł��B");
	for (auto & drink : m_drink)
	{
		Utility::DrawChara("�E");
		//CString�̃o�b�t�@���擾�����O�̕\��
		wchar_t* wc = drink->GetName().GetBuffer();
		wcout << wc;
		//�l�i�̕\��
		cout<< ":" << drink->GetPrice() << "�~" << endl;
	}
}

//----------------------------------------------------------------------
//! @brief �������󂯎��
//!
//! @param[in] ����
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void VendingMachine::ReceiveMoney(std::unique_ptr<Money> money)
{
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_receivedMoney->AddMoney(i, money->GetMoney(i));
	}
}

//----------------------------------------------------------------------
//! @brief �h�����N���o��
//!
//! @param[in] �h�����N�̖��O
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void VendingMachine::DischargeDrink(CString drinkName)
{

	for (int i = 0; i < DRINKTYPE_NUM; i++)
	{
		if (m_drink[i]->GetName() == drinkName)
		{
			//�h�����N�̍݌ɂ��Ȃ��ꍇ
			if (m_drinkStock[i] <= 0) break;
			m_boughtName = drinkName;
			//���ނ���v�Z����
			int change = ChangePrice();
			//���ނ肪�}�C�i�X�̏ꍇ
			if (change < 0)
			{
				Utility::DrawCharaNewLine("����������܂���B");
				return;
			}
			//�݌ɂ�����ꍇ
			m_drinkStock[i]--;
			wcout << drinkName.GetBuffer() << L"���o�Ă��܂���";
			return;
		}
	}
	Utility::DrawCharaNewLine("�݌ɐ؂�ł�");
}

//----------------------------------------------------------------------
//! @brief ������v�Z����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void VendingMachine::Calculate()
{
	int change = ChangePrice();
	//����̌v�Z���I���܂�
	while (change > 0)
	{
		//1000�~�D�̍݌ɂ��m�F����
		MoneyStockCheck(change, Money::BILL1000, Money::sBILL1000_VALUE);
		//500�~�ʂ̍݌ɂ��m�F����
		MoneyStockCheck(change, Money::COIN500, Money::sCOIN500_VALUE);
		//100�~�ʂ̍݌ɂ��m�F����
		MoneyStockCheck(change, Money::COIN100, Money::sCOIN100_VALUE);
		//50�~�ʂ̍݌ɂ��m�F����
		MoneyStockCheck(change, Money::COIN50, Money::sCOIN50_VALUE);
		//10�~�ʂ̍݌ɂ��m�F����
		MoneyStockCheck(change, Money::COIN10, Money::sCOIN10_VALUE);
	}
	Utility::DrawCharaNewLine("������o���܂��B");
	//�݌ɂ������
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_moneyNum->DeleteMoney(i, m_changeMoney->GetMoney(i));
	}
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		cout << m_changeMoney->GetValue(i) << "�~��" << m_changeMoney->GetMoney(i) << "���o���܂����B" << endl;
	}
}

//----------------------------------------------------------------------
//! @brief �󂯎�������������̂܂܂��ނ�ɂ���
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void VendingMachine::ToChange()
{
	//���ނ�ɂ���
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_changeMoney->AddMoney(i, m_receivedMoney->GetMoney(i));
	}
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		cout << m_changeMoney->GetValue(i) << "�~��" << m_changeMoney->GetMoney(i) << "���o���܂����B" << endl;
	}
}

//----------------------------------------------------------------------
//! @brief �󂯎�������������̂܂܂��ނ�ɂ���
//!
//! @param[in] �Ȃ�
//!
//! @return ���ނ�̉��i
//----------------------------------------------------------------------
int VendingMachine::ChangePrice()
{
	//���i
	int price = 0;
	for (int i = 0; i < DRINKTYPE_NUM; i++)
	{
		if (m_drink[i]->GetName() == m_boughtName)
		{
			price = m_drink[i]->GetPrice();
			break;
		}
	}
	//�󂯎���������̍��v
	int receivedMoney = 0;
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		receivedMoney += m_receivedMoney->GetMoney(i) * m_receivedMoney->GetValue(i);
	}
	//����
	int change = receivedMoney - price;
	return change;
}

//----------------------------------------------------------------------
//! @brief �����̍݌ɂ��m�F����
//!
//! @param[in] ����A�����̎�ށA�����̉��l
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void VendingMachine::MoneyStockCheck(int& change, int kind, int value)
{
	//�����̍݌ɂ�����A����̋��z�������̉��l��荂���ꍇ
	if (m_moneyNum->GetMoney(kind) > 0 && change >= value)
	{
		change -= value;
		//���ނ�����߂�
		m_changeMoney->AddMoney(kind, 1);
		//�ċA
		MoneyStockCheck(change, kind, value);
	}
}

