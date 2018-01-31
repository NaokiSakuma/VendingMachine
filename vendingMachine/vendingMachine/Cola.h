//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Cola.h
//!
//! @brief  �R�[���N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include "Drink.h"

//�R�[���N���X
class Cola final : public CDrink
{
public:
	//�R���X�g���N�^
	Cola(int price) { m_price = price; m_name = "�R�[��"; }
	//�f�X�g���N�^
	~Cola() { }
	//�l�i��getter
	int GetPrice() override { return m_price; }
	//���O��getter
	CString GetName() override { return m_name; };
};