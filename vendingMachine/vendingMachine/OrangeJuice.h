//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   OrangeJuice.h
//!
//! @brief  オレンジジュースクラスのヘッダファイル
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//インクルード
#include "Drink.h"

//オレンジジュースクラス
class OrangeJuice final : public CDrink
{
public:
	//コンストラクタ
	OrangeJuice(int price) { m_price = price; m_name = "オレンジジュース"; }
	//デストラクタ
	~OrangeJuice() { }
	////値段のgetter
	//int GetPrice() override { return m_price; }
	////名前のgetter
	//CString GetName() override { return m_name; };
};