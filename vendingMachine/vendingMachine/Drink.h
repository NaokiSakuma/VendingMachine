//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Drink.h
//!
//! @brief  ドリンククラスのヘッダファイル
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//インクルード
#include "IVendingItem.h"

//ドリンククラス
class CDrink : public IVendingItem
{
public:
	//コンストラクタ
	CDrink(int price){ m_price = price; m_name = "Drink"; }
	//デフォルトコンストラクタ
	CDrink() {}
	//デストラクタ
	~CDrink() {}
	//値段のgetter
	virtual int GetPrice() { return m_price; };
	//名前のgetter
	virtual CString GetName() { return m_name; };
protected:
	//値段
	int m_price;
	//名前
	CString m_name;
};