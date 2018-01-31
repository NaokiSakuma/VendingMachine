//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Cola.h
//!
//! @brief  コーラクラスのヘッダファイル
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//インクルード
#include "Drink.h"

//コーラクラス
class Cola final : public CDrink
{
public:
	//コンストラクタ
	Cola(int price) { m_price = price; m_name = "コーラ"; }
	//デストラクタ
	~Cola() { }
	//値段のgetter
	int GetPrice() override { return m_price; }
	//名前のgetter
	CString GetName() override { return m_name; };
};