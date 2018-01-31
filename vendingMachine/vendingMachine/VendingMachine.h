//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   VendingMachine.h
//!
//! @brief  �����̔��@�N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include <memory>
#include <list>
#include <vector>
#include "Money.h"
#include "Drink.h"

//�����̔��@�N���X
class VendingMachine 
{
public:
	//�R���X�g���N�^
	VendingMachine();
	//�f�X�g���N�^
	~VendingMachine() {}
	//�����ݒ�
	void Initialize();
	//�̔����Ă�����̂̎�ނ�\��
	void ShowAllKind();
	//�������󂯎��
	void ReceiveMoney(std::unique_ptr<Money> money);
	//�h�����N���o��
	void DischargeDrink(CString drinkName);
	//������v�Z����
	void Calculate();
	//�󂯎�������������̂܂܂��ނ�ɂ���
	void ToChange();
	//����̉��i
	int ChangePrice();
	//�萔
#pragma region Constant
	//�d�݂̍݌ɖ���
	static const int sCOINSTOCK_NUM;
	//���ݕ��̍݌ɖ{��
	static const int sDRINKSTOCK_NUM;
	//�R�[���̒l�i
	static const int sCOLA_PRICE;
	//�I�����W�W���[�X�̒l�i
	static const int sORANGE_PRICE;
#pragma endregion

	//���ݕ��̎��
	enum DrinkType
	{
		COLA,			//�R�[��
		CIDER,			//�T�C�_�[
		DRINKTYPE_NUM	//���ݕ��̎�ނ̐�
	};
#pragma region Getter
	//����
	std::unique_ptr<Money>GetChange() { return std::move(m_changeMoney); }
	//�h�����N�̎���
	std::unique_ptr<CDrink> GetDrink(int kind) { return std::move(m_drink[kind]); }
	//�h�����N�̃|�C���^
	CDrink* GetDrinkCopy(int kind) { return m_drink[kind].get(); }

#pragma endregion

private:
	//�����̖���
	std::unique_ptr<Money> m_moneyNum;
	//���ݕ��̍݌�
	int m_drinkStock[DRINKTYPE_NUM];
	//���ݕ�
	std::vector<std::unique_ptr<CDrink>> m_drink;
	//�󂯎��������
	std::unique_ptr<Money> m_receivedMoney;
	//���ނ�
	std::unique_ptr<Money> m_changeMoney;
	//�w�����ꂽ�h�����N�̖��O
	CString m_boughtName;
	//�����̍݌ɂ��m�F����
	void MoneyStockCheck(int& change, int kind, int value);
};