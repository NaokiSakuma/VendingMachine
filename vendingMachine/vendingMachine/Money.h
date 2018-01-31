//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Money.h
//!
//! @brief  �����N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�����N���X
class Money
{
public:
	//�R���X�g���N�^
	Money();
	//�f�X�g���N�^
	~Money() {}
	//�����̍݌ɂ̒ǉ�
	void AddMoney(int kind, int addNum);
	//�����̍݌ɂ̍폜
	void DeleteMoney(int kind, int deleteNum);
	//�����̍݌ɂ�getter
	int GetMoney(int kind);
	//�����̉��l��getter
	int GetValue(int& kind);
	//���������Z�b�g����
	void Reset();
	//�����̎��
	enum MoneyType
	{
		BILL1000,     //1000�~�D
		COIN500,	  //500�~��
		COIN100,	  //100�~��
		COIN50,		  //50�~��
		COIN10,		  //10�~��
		MONEYTYPE_NUM //�d�݂̎�ނ̐�
	};
#pragma region Constant
	//1000�~�D�̉��l
	static const int sBILL1000_VALUE;
	//500�~�ʂ̉��l
	static const int sCOIN500_VALUE;
	//100�~�ʂ̉��l
	static const int sCOIN100_VALUE;
	//50�~�ʂ̉��l
	static const int sCOIN50_VALUE;
	//10�~�ʂ̉��l
	static const int sCOIN10_VALUE;
#pragma endregion

private:
	//�����̍݌�
	int m_moneyStock[MONEYTYPE_NUM];
	//�����̉��l
	int m_value[MONEYTYPE_NUM];
};