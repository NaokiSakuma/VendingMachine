//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Utility.h
//!
//! @brief  �֗��N���X�̃w�b�_�t�@�C��
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//�C���N���[�h
#include <atlstr.h>

//�֗��N���X
class Utility
{
public:
	//�����̕\��
	static void DrawChara(const char* messe);
	static void DrawChara(int messe);

	//�����̕\���A���s����
	static void DrawCharaNewLine(const char* messe);
	static void DrawCharaNewLine(int messe);

	//�G���[�`�F�b�N
	static void ErrorCheck(const char * messe);
	//�o�b�t�@�̃N���A
	static void ClearBuf();
};