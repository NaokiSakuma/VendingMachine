//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Utility.cpp
//!
//! @brief  �֗��N���X�̃\�[�X�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//�C���N���[�h
#include <iostream>
#include "Utility.h"

using namespace std;

//----------------------------------------------------------------------
//! @brief �����̕\��
//!
//! @param[in] �\�����������b�Z�[�W
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Utility::DrawChara(const char * messe)
{
	cout << messe;
}
void Utility::DrawChara(int messe)
{
	cout << messe;
}


//----------------------------------------------------------------------
//! @brief �����̕\���A���s����
//!
//! @param[in] �\�����������b�Z�[�W
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Utility::DrawCharaNewLine(const char * messe)
{
	cout << messe << endl;
}
void Utility::DrawCharaNewLine(int messe)
{
	cout << messe << endl;
}

//----------------------------------------------------------------------
//! @brief �G���[�`�F�b�N
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Utility::ErrorCheck(const char * messe)
{
	ClearBuf();
	DrawCharaNewLine(messe);
}

//----------------------------------------------------------------------
//! @brief �o�b�t�@�̃N���A
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Utility::ClearBuf()
{
	//�G���[�t���O����菜��
	cin.clear();
	//�o�b�t�@�̃N���A
	cin.ignore(cin.rdbuf()->in_avail());
}

