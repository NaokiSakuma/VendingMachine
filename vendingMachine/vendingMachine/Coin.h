//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Coin.h
//!
//! @brief  �����N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

class Coin
{
public:
	//�R���X�g���N�^
	Coin();
	//�f�X�g���N�^
	~Coin();

	//�����̎��
	enum CoinType
	{
		COIN500,	 //500�~��
		COIN100,	 //100�~��
		COIN50,		 //50�~��
		COIN10,		 //10�~��
		COINTYPE_NUM //�d�݂̎�ނ̐�
	};

private:
};