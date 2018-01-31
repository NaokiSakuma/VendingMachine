//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Drink.h
//!
//! @brief  �h�����N�N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include "IVendingItem.h"

//�h�����N�N���X
class CDrink : public IVendingItem
{
public:
	//�R���X�g���N�^
	CDrink(int price){ m_price = price; m_name = "Drink"; }
	//�f�t�H���g�R���X�g���N�^
	CDrink() {}
	//�f�X�g���N�^
	~CDrink() {}
	//�l�i��getter
	virtual int GetPrice() { return m_price; };
	//���O��getter
	virtual CString GetName() { return m_name; };
protected:
	//�l�i
	int m_price;
	//���O
	CString m_name;
};