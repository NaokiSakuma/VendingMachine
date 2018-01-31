//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   VendingMachine.cpp
//!
//! @brief  自動販売機クラスのソースファイル
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//インクルード
#include <iostream>
#include "VendingMachine.h"
#include "OrangeJuice.h"
#include "Cola.h"
#include "Utility.h"

//定数
#pragma region Constant
//硬貨の在庫枚数
const int VendingMachine::sCOINSTOCK_NUM = 20;
//飲み物の在庫本数
const int VendingMachine::sDRINKSTOCK_NUM = 10;
//コーラの値段
const int VendingMachine::sCOLA_PRICE = 120;
//オレンジジュースの値段
const int VendingMachine::sORANGE_PRICE = 100;
#pragma endregion

//名前空間
using namespace std;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//----------------------------------------------------------------------
VendingMachine::VendingMachine()
{
}

//----------------------------------------------------------------------
//! @brief 初期設定
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void VendingMachine::Initialize()
{
	//硬貨の在庫を決める
	m_moneyNum = make_unique<Money>();
	//1000円札は出ない
	for (int i = Money::BILL1000; i < Money::MONEYTYPE_NUM; i++)
	{
		m_moneyNum->AddMoney(i, sCOINSTOCK_NUM);
	}
	//飲み物の在庫を決める
	for (int i = 0; i < DRINKTYPE_NUM; i++)
	{
		m_drinkStock[i] = sDRINKSTOCK_NUM;
	}
	m_receivedMoney = make_unique<Money>();
	m_changeMoney = make_unique<Money>();
	//コーラ
	std::unique_ptr<CDrink> cola = std::make_unique<Cola>(sCOLA_PRICE);
	m_drink.push_back(move(cola));
	//オレンジジュース
	std::unique_ptr<CDrink> orangeJuice = std::make_unique<OrangeJuice>(sORANGE_PRICE);
	m_drink.push_back(move(orangeJuice));
}

//----------------------------------------------------------------------
//! @brief 販売しているものの種類を表示
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void VendingMachine::ShowAllKind()
{
	Utility::DrawCharaNewLine("売っている物の一覧です。");
	for (auto & drink : m_drink)
	{
		Utility::DrawChara("・");
		//CStringのバッファを取得し名前の表示
		wchar_t* wc = drink->GetName().GetBuffer();
		wcout << wc;
		//値段の表示
		cout<< ":" << drink->GetPrice() << "円" << endl;
	}
}

//----------------------------------------------------------------------
//! @brief お金を受け取る
//!
//! @param[in] お金
//!
//! @return なし
//----------------------------------------------------------------------
void VendingMachine::ReceiveMoney(std::unique_ptr<Money> money)
{
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_receivedMoney->AddMoney(i, money->GetMoney(i));
	}
}

//----------------------------------------------------------------------
//! @brief ドリンクを出す
//!
//! @param[in] ドリンクの名前
//!
//! @return なし
//----------------------------------------------------------------------
void VendingMachine::DischargeDrink(CString drinkName)
{

	for (int i = 0; i < DRINKTYPE_NUM; i++)
	{
		if (m_drink[i]->GetName() == drinkName)
		{
			//ドリンクの在庫がない場合
			if (m_drinkStock[i] <= 0) break;
			m_boughtName = drinkName;
			//お釣りを計算する
			int change = ChangePrice();
			//お釣りがマイナスの場合
			if (change < 0)
			{
				Utility::DrawCharaNewLine("お金が足りません。");
				return;
			}
			//在庫がある場合
			m_drinkStock[i]--;
			wcout << drinkName.GetBuffer() << L"が出てきました";
			return;
		}
	}
	Utility::DrawCharaNewLine("在庫切れです");
}

//----------------------------------------------------------------------
//! @brief おつりを計算する
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void VendingMachine::Calculate()
{
	int change = ChangePrice();
	//おつりの計算が終わるまで
	while (change > 0)
	{
		//1000円札の在庫を確認する
		MoneyStockCheck(change, Money::BILL1000, Money::sBILL1000_VALUE);
		//500円玉の在庫を確認する
		MoneyStockCheck(change, Money::COIN500, Money::sCOIN500_VALUE);
		//100円玉の在庫を確認する
		MoneyStockCheck(change, Money::COIN100, Money::sCOIN100_VALUE);
		//50円玉の在庫を確認する
		MoneyStockCheck(change, Money::COIN50, Money::sCOIN50_VALUE);
		//10円玉の在庫を確認する
		MoneyStockCheck(change, Money::COIN10, Money::sCOIN10_VALUE);
	}
	Utility::DrawCharaNewLine("おつりを出します。");
	//在庫から引く
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_moneyNum->DeleteMoney(i, m_changeMoney->GetMoney(i));
	}
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		cout << m_changeMoney->GetValue(i) << "円を" << m_changeMoney->GetMoney(i) << "枚出しました。" << endl;
	}
}

//----------------------------------------------------------------------
//! @brief 受け取ったお金をそのままお釣りにする
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void VendingMachine::ToChange()
{
	//お釣りにする
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_changeMoney->AddMoney(i, m_receivedMoney->GetMoney(i));
	}
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		cout << m_changeMoney->GetValue(i) << "円が" << m_changeMoney->GetMoney(i) << "枚出しました。" << endl;
	}
}

//----------------------------------------------------------------------
//! @brief 受け取ったお金をそのままお釣りにする
//!
//! @param[in] なし
//!
//! @return お釣りの価格
//----------------------------------------------------------------------
int VendingMachine::ChangePrice()
{
	//価格
	int price = 0;
	for (int i = 0; i < DRINKTYPE_NUM; i++)
	{
		if (m_drink[i]->GetName() == m_boughtName)
		{
			price = m_drink[i]->GetPrice();
			break;
		}
	}
	//受け取ったお金の合計
	int receivedMoney = 0;
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		receivedMoney += m_receivedMoney->GetMoney(i) * m_receivedMoney->GetValue(i);
	}
	//おつり
	int change = receivedMoney - price;
	return change;
}

//----------------------------------------------------------------------
//! @brief お金の在庫を確認する
//!
//! @param[in] おつり、お金の種類、お金の価値
//!
//! @return なし
//----------------------------------------------------------------------
void VendingMachine::MoneyStockCheck(int& change, int kind, int value)
{
	//お金の在庫があり、おつりの金額がお金の価値より高い場合
	if (m_moneyNum->GetMoney(kind) > 0 && change >= value)
	{
		change -= value;
		//お釣りを求める
		m_changeMoney->AddMoney(kind, 1);
		//再帰
		MoneyStockCheck(change, kind, value);
	}
}

