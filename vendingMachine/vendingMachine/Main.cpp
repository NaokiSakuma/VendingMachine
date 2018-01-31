//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Main.cpp
//!
//! @brief  メイン文のソースファイル
//!
//! @date   2018/01/30
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//インクルード
#include <iostream>
#include <string>
#include "Buyer.h"
#include "VendingMachine.h"

//main文
int main()
{
	//日本語の設定
	setlocale(LC_ALL, "japanese");
	//買う人
	Buyer buyer;
	//自動販売機
	VendingMachine vendingMachine;
	buyer.Initialize();
	vendingMachine.Initialize();
	//お金を入れる
	buyer.PutInMoney();

	//お金を受け取る
	vendingMachine.ReceiveMoney(buyer.GetAmountMoney());
	//販売しているものを表示
	vendingMachine.ShowAllKind();
	//買うかどうか
	buyer.IsBuy();
	//買うなら
	if (buyer.GetIsBuy())
	{
		//ドリンクの取得
		std::vector<CDrink*> drink;
		for (int i = 0; i < VendingMachine::DRINKTYPE_NUM; i++)
		{
			drink.push_back(vendingMachine.GetDrinkCopy(i));
		}
		//ドリンクを買う
		vendingMachine.DischargeDrink(buyer.DecideBuy(drink));
		vendingMachine.Calculate();
		buyer.ReceiveMoney(vendingMachine.GetChange());
	}
	//買わないなら
	else
	{
		vendingMachine.ToChange();
		buyer.ReceiveMoney(vendingMachine.GetChange());
	}
	system("PAUSE");
	return 0;
}