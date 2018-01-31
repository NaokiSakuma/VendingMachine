//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Utility.cpp
//!
//! @brief  便利クラスのソースファイル
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//インクルード
#include <iostream>
#include "Utility.h"

using namespace std;

//----------------------------------------------------------------------
//! @brief 文字の表示
//!
//! @param[in] 表示したいメッセージ
//!
//! @return なし
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
//! @brief 文字の表示、改行あり
//!
//! @param[in] 表示したいメッセージ
//!
//! @return なし
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
//! @brief エラーチェック
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Utility::ErrorCheck(const char * messe)
{
	ClearBuf();
	DrawCharaNewLine(messe);
}

//----------------------------------------------------------------------
//! @brief バッファのクリア
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Utility::ClearBuf()
{
	//エラーフラグを取り除く
	cin.clear();
	//バッファのクリア
	cin.ignore(cin.rdbuf()->in_avail());
}

