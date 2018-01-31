//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   VendingItem.h
//!
//! @brief  �����̔��@�̃A�C�e���̃C���^�[�t�F�[�X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include <atlstr.h>

//�����̔��@�̃A�C�e���C���^�[�t�F�[�X
__interface IVendingItem
{
public:
	//�l�i��getter
	virtual int GetPrice() = 0;
	//���O��getter
	virtual CString GetName() = 0;
};