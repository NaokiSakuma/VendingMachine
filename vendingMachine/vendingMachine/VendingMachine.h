//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   VendingMachine.h
//!
//! @brief  自動販売機クラスのヘッダファイル
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//インクルード
#include <memory>
#include <list>
#include <vector>
#include "Money.h"
#include "Drink.h"

//自動販売機クラス
class VendingMachine 
{
public:
	//コンストラクタ
	VendingMachine();
	//デストラクタ
	~VendingMachine() {}
	//初期設定
	void Initialize();
	//販売しているものの種類を表示
	void ShowAllKind();
	//お金を受け取る
	void ReceiveMoney(std::unique_ptr<Money> money);
	//ドリンクを出す
	void DischargeDrink(CString drinkName);
	//おつりを計算する
	void Calculate();
	//受け取ったお金をそのままお釣りにする
	void ToChange();
	//おつりの価格
	int ChangePrice();
	//定数
#pragma region Constant
	//硬貨の在庫枚数
	static const int sCOINSTOCK_NUM;
	//飲み物の在庫本数
	static const int sDRINKSTOCK_NUM;
	//コーラの値段
	static const int sCOLA_PRICE;
	//オレンジジュースの値段
	static const int sORANGE_PRICE;
#pragma endregion

	//飲み物の種類
	enum DrinkType
	{
		COLA,			//コーラ
		CIDER,			//サイダー
		DRINKTYPE_NUM	//飲み物の種類の数
	};
#pragma region Getter
	//おつり
	std::unique_ptr<Money>GetChange() { return std::move(m_changeMoney); }
	//ドリンクの実態
	std::unique_ptr<CDrink> GetDrink(int kind) { return std::move(m_drink[kind]); }
	//ドリンクのポインタ
	CDrink* GetDrinkCopy(int kind) { return m_drink[kind].get(); }

#pragma endregion

private:
	//お金の枚数
	std::unique_ptr<Money> m_moneyNum;
	//飲み物の在庫
	int m_drinkStock[DRINKTYPE_NUM];
	//飲み物
	std::vector<std::unique_ptr<CDrink>> m_drink;
	//受け取ったお金
	std::unique_ptr<Money> m_receivedMoney;
	//お釣り
	std::unique_ptr<Money> m_changeMoney;
	//購入されたドリンクの名前
	CString m_boughtName;
	//お金の在庫を確認する
	void MoneyStockCheck(int& change, int kind, int value);
};