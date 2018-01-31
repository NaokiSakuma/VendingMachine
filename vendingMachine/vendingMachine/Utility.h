//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Utility.h
//!
//! @brief  便利クラスのヘッダファイル
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//インクルード
#include <atlstr.h>

//便利クラス
class Utility
{
public:
	//文字の表示
	static void DrawChara(const char* messe);
	static void DrawChara(int messe);

	//文字の表示、改行あり
	static void DrawCharaNewLine(const char* messe);
	static void DrawCharaNewLine(int messe);

	//エラーチェック
	static void ErrorCheck(const char * messe);
	//バッファのクリア
	static void ClearBuf();
};