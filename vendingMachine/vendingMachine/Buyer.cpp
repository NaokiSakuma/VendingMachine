//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.cpp
//!
//! @brief  �v���C���N���X�̃\�[�X�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//�C���N���[�h
#include <cctype>
#include "Buyer.h"
#include "Utility.h"
#include <string>

//���O���
using namespace std;

//�萔
const int Buyer::sMONEY_MAXNUM = 20;
//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Buyer::Buyer()
	:m_possessionMoney(0)
	,m_isBuy(false)
	,m_isDecision(false)
{
}

//----------------------------------------------------------------------
//! @brief �����ݒ�
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Buyer::Initialize()
{
	m_moneyNum = make_unique<Money>();
	m_amountMoney = make_unique<Money>();
	Utility::DrawCharaNewLine("�����̐�����͂��Ă�������(�e20���܂�)�B" );
	//�����̐��̓���
	SetMoneyNum("1000�~�D "  , Money::BILL1000);
	SetMoneyNum("   500�~ "  , Money::COIN500);
	SetMoneyNum("   100�~ "  , Money::COIN100);
	SetMoneyNum("    50�~ "  , Money::COIN50);
	SetMoneyNum("    10�~ "  , Money::COIN10);

	//�������̌v�Z
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_possessionMoney += m_moneyNum->GetMoney(i) * m_moneyNum->GetValue(i);
	}
	cout << "�M���̏�������" << m_possessionMoney << "�~�ł��B" << endl;
}

//----------------------------------------------------------------------
//! @brief ����������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Buyer::PutInMoney()
{
	Utility::DrawCharaNewLine("���~������܂����H");
	//�x�������������
	PayMoney("1000�~�D����������܂����H(������:", m_moneyNum->GetMoney(Money::BILL1000),Money::BILL1000);
	PayMoney("   500�~����������܂����H(������:", m_moneyNum->GetMoney(Money::COIN500) ,Money::COIN500);
	PayMoney("   100�~����������܂����H(������:", m_moneyNum->GetMoney(Money::COIN100) ,Money::COIN100);
	PayMoney("    50�~����������܂����H(������:", m_moneyNum->GetMoney(Money::COIN50)  ,Money::COIN50);
	PayMoney("    10�~����������܂����H(������:", m_moneyNum->GetMoney(Money::COIN10)  ,Money::COIN10);

	m_possessionMoney = 0;
	//�������̌v�Z
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_possessionMoney += m_moneyNum->GetMoney(i) * m_moneyNum->GetValue(i);
	}
	cout << "�M���̏�������" << m_possessionMoney << "�~�ł��B" << endl;

}

//----------------------------------------------------------------------
//! @brief ���i�𔃂����ǂ���
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Buyer::IsBuy()
{
	Utility::DrawCharaNewLine("�w�����܂����H 1:���� 0:����Ȃ�");
	//����
	bool buy;
	cin >> buy;
	//buy��true�ł�false�ł��Ȃ��ꍇ
	if (cin.fail())
	{
		Utility::ErrorCheck("�s���Ȓl�ł��B");
		//�ċA
		IsBuy();
	}
	//�l�̓���
	m_isBuy = buy;
	//�o�b�t�@�̃N���A
	Utility::ClearBuf();

}

//----------------------------------------------------------------------
//! @brief �������̂����߂�
//!
//! @param[in] �h�����N
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
CString Buyer::DecideBuy(const std::vector<CDrink*>& drink)
{
	//������
	CString cstr;
	string str;
	Utility::DrawCharaNewLine("���𔃂��܂����H");
	//���������
	cin >> str;
	//string��CString�ɕϊ�
	cstr = str.c_str();
	//CString��wchar_t�ɕϊ�
	wchar_t* wc = cstr.GetBuffer();
	for (auto & drinkName : drink)
	{
		//CString�̃o�b�t�@���擾�����O�̕\��
		wchar_t* dWc = drinkName->GetName().GetBuffer();
		//���͂������̂ƍw���o������̖̂��O���r
		int result = std::wcscmp(wc, dWc);
		//�������O�������ꍇ
		if (result == 0)
		{
			m_isDecision = true;
			break;
		}
	}
	//�w���Ɏ��s�����ꍇ
	if(!m_isDecision)
	{
		//�G���[�`�F�b�N
		Utility::ErrorCheck("�w���Ɏ��s���܂����B");
		//�ċA
		DecideBuy(drink);
	}

	return wc;
}

//----------------------------------------------------------------------
//! @brief �������󂯎��
//!
//! @param[in] ����
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Buyer::ReceiveMoney(std::unique_ptr<Money> money)
{
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_moneyNum->AddMoney(i, money->GetMoney(i));
	}
	m_possessionMoney = 0;
	//�������̌v�Z
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_possessionMoney += m_moneyNum->GetMoney(i) * m_moneyNum->GetValue(i);
	}
	cout << "�M���̏�������" << m_possessionMoney << "�~�ł��B" << endl;

}

//----------------------------------------------------------------------
//! @brief �����̖������Z�b�g����
//!
//! @param[in] ���b�Z�[�W�A���������߂邨��
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Buyer::SetMoneyNum(const char * messe, int setNum)
{
	//����
	int num;
	//�����̕\��
	Utility::DrawChara(messe);
	//�����̃Z�b�g
	cin >> num;
	//�G���[�`�F�b�N�A�������̓}�C�i�X�̒l����͂����ꍇ�A�������͍ő喇����葽���l����͂����ꍇ
	if (cin.fail() || num < 0 || num > sMONEY_MAXNUM)
	{
		num = 0;
		Utility::ErrorCheck("�s���Ȓl�ł��B");
		//�ċA
		SetMoneyNum(messe, setNum);
	}
	//�l�̑}��
	m_moneyNum->AddMoney(setNum,num);
	//�o�b�t�@�̃N���A
	Utility::ClearBuf();
}

//----------------------------------------------------------------------
//! @brief �������x����
//!
//! @param[in] ���b�Z�[�W�A���������A���
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Buyer::PayMoney(const char* messe, int payNum, int kind)
{
	//����
	int num;

	//�����̕\��
	Utility::DrawChara(messe);
	Utility::DrawChara(payNum);
	Utility::DrawChara("��)");

	//�����̃Z�b�g
	cin >> num;
	//�G���[�`�F�b�N�A�������͏���������葽����������͂����ꍇ�A�������̓}�C�i�X�̒l����͂����ꍇ
	if (cin.fail() || num > m_moneyNum->GetMoney(kind) || num < 0)
	{
		num = 0;
		Utility::ErrorCheck("�s���Ȓl�ł��B");
		//�ċA
		PayMoney(messe, payNum, kind);
	}
	//�l�̑}��
	m_moneyNum->DeleteMoney(kind, num);
	//�x�������z
	m_amountMoney->AddMoney(kind, num);
	//�o�b�t�@�̃N���A
	Utility::ClearBuf();

}
