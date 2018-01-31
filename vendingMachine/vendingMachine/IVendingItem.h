//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   VendingItem.h
//!
//! @brief  自動販売機のアイテムのインターフェースのヘッダファイル
//!
//! @date   2018/01/28
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//インクルード
#include <atlstr.h>

//自動販売機のアイテムインターフェース
__interface IVendingItem
{
public:
	//値段のgetter
	virtual int GetPrice() = 0;
	//名前のgetter
	virtual CString GetName() = 0;
};