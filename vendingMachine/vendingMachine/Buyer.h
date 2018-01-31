//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.h
//!
//! @brief  プレイヤクラスのヘッダファイル
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//インクルード
#include <memory>
#include <iostream>
#include <vector>
#include "Money.h"
#include "Drink.h"

//プレイヤクラス
class Buyer
{
public:
	//コンストラクタ
	Buyer();
	//デストラクタ
	~Buyer() {}
	//初期設定
	void Initialize();
	//お金を入れる
	void PutInMoney();
	//商品を買うかどうか
	void IsBuy();
	//買うものを決める
	CString DecideBuy(const std::vector<CDrink*>& drink);
	//お金を受け取る
	void ReceiveMoney(std::unique_ptr<Money> money);
#pragma region Getter
	//支払った額
	std::unique_ptr<Money> GetAmountMoney() { return std::move(m_amountMoney); }
	//買うかどうか
	bool GetIsBuy() { return m_isBuy; }
#pragma endregion

private:
	//お金の枚数
	std::unique_ptr<Money> m_moneyNum;
	//所持金
	int m_possessionMoney;
	//支払った額
	std::unique_ptr<Money> m_amountMoney;
	//買うかどうか
	bool m_isBuy;
	//決定したかどうか
	bool m_isDecision;
	//お金の枚数の最大数
	static const int sMONEY_MAXNUM;
	//お金の枚数をセットする
	void SetMoneyNum(const char* messe, int setNum);
	//お金を支払う
	void PayMoney(const char* messe, int payNum, int kind);
};