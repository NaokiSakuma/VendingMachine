//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   OrangeJuice.h
//!
//! @brief  �I�����W�W���[�X�N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include "Drink.h"

//�I�����W�W���[�X�N���X
class OrangeJuice final : public CDrink
{
public:
	//�R���X�g���N�^
	OrangeJuice(int price) { m_price = price; m_name = "�I�����W�W���[�X"; }
	//�f�X�g���N�^
	~OrangeJuice() { }
	////�l�i��getter
	//int GetPrice() override { return m_price; }
	////���O��getter
	//CString GetName() override { return m_name; };
};