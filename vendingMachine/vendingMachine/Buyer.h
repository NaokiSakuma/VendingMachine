//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.h
//!
//! @brief  �v���C���N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include <memory>
#include <iostream>
#include <vector>
#include "Money.h"
#include "Drink.h"

//�v���C���N���X
class Buyer
{
public:
	//�R���X�g���N�^
	Buyer();
	//�f�X�g���N�^
	~Buyer() {}
	//�����ݒ�
	void Initialize();
	//����������
	void PutInMoney();
	//���i�𔃂����ǂ���
	void IsBuy();
	//�������̂����߂�
	CString DecideBuy(const std::vector<CDrink*>& drink);
	//�������󂯎��
	void ReceiveMoney(std::unique_ptr<Money> money);
#pragma region Getter
	//�x�������z
	std::unique_ptr<Money> GetAmountMoney() { return std::move(m_amountMoney); }
	//�������ǂ���
	bool GetIsBuy() { return m_isBuy; }
#pragma endregion

private:
	//�����̖���
	std::unique_ptr<Money> m_moneyNum;
	//������
	int m_possessionMoney;
	//�x�������z
	std::unique_ptr<Money> m_amountMoney;
	//�������ǂ���
	bool m_isBuy;
	//���肵�����ǂ���
	bool m_isDecision;
	//�����̖����̍ő吔
	static const int sMONEY_MAXNUM;
	//�����̖������Z�b�g����
	void SetMoneyNum(const char* messe, int setNum);
	//�������x����
	void PayMoney(const char* messe, int payNum, int kind);
};