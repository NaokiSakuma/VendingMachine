//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.cpp
//!
//! @brief  プレイヤクラスのソースファイル
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//インクルード
#include <cctype>
#include "Buyer.h"
#include "Utility.h"
#include <string>

//名前空間
using namespace std;

//定数
const int Buyer::sMONEY_MAXNUM = 20;
//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//----------------------------------------------------------------------
Buyer::Buyer()
	:m_possessionMoney(0)
	,m_isBuy(false)
	,m_isDecision(false)
{
}

//----------------------------------------------------------------------
//! @brief 初期設定
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Buyer::Initialize()
{
	m_moneyNum = make_unique<Money>();
	m_amountMoney = make_unique<Money>();
	Utility::DrawCharaNewLine("お金の数を入力してください(各20枚まで)。" );
	//お金の数の入力
	SetMoneyNum("1000円札 "  , Money::BILL1000);
	SetMoneyNum("   500円 "  , Money::COIN500);
	SetMoneyNum("   100円 "  , Money::COIN100);
	SetMoneyNum("    50円 "  , Money::COIN50);
	SetMoneyNum("    10円 "  , Money::COIN10);

	//所持金の計算
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_possessionMoney += m_moneyNum->GetMoney(i) * m_moneyNum->GetValue(i);
	}
	cout << "貴方の所持金は" << m_possessionMoney << "円です。" << endl;
}

//----------------------------------------------------------------------
//! @brief お金を入れる
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Buyer::PutInMoney()
{
	Utility::DrawCharaNewLine("何円分いれますか？");
	//支払う枚数を入力
	PayMoney("1000円札を何枚入れますか？(所持数:", m_moneyNum->GetMoney(Money::BILL1000),Money::BILL1000);
	PayMoney("   500円を何枚入れますか？(所持数:", m_moneyNum->GetMoney(Money::COIN500) ,Money::COIN500);
	PayMoney("   100円を何枚入れますか？(所持数:", m_moneyNum->GetMoney(Money::COIN100) ,Money::COIN100);
	PayMoney("    50円を何枚入れますか？(所持数:", m_moneyNum->GetMoney(Money::COIN50)  ,Money::COIN50);
	PayMoney("    10円を何枚入れますか？(所持数:", m_moneyNum->GetMoney(Money::COIN10)  ,Money::COIN10);

	m_possessionMoney = 0;
	//所持金の計算
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_possessionMoney += m_moneyNum->GetMoney(i) * m_moneyNum->GetValue(i);
	}
	cout << "貴方の所持金は" << m_possessionMoney << "円です。" << endl;

}

//----------------------------------------------------------------------
//! @brief 商品を買うかどうか
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Buyer::IsBuy()
{
	Utility::DrawCharaNewLine("購入しますか？ 1:買う 0:買わない");
	//入力
	bool buy;
	cin >> buy;
	//buyがtrueでもfalseでもない場合
	if (cin.fail())
	{
		Utility::ErrorCheck("不正な値です。");
		//再帰
		IsBuy();
	}
	//値の入力
	m_isBuy = buy;
	//バッファのクリア
	Utility::ClearBuf();

}

//----------------------------------------------------------------------
//! @brief 買うものを決める
//!
//! @param[in] ドリンク
//!
//! @return なし
//----------------------------------------------------------------------
CString Buyer::DecideBuy(const std::vector<CDrink*>& drink)
{
	//文字列
	CString cstr;
	string str;
	Utility::DrawCharaNewLine("何を買いますか？");
	//文字を入力
	cin >> str;
	//stringをCStringに変換
	cstr = str.c_str();
	//CStringをwchar_tに変換
	wchar_t* wc = cstr.GetBuffer();
	for (auto & drinkName : drink)
	{
		//CStringのバッファを取得し名前の表示
		wchar_t* dWc = drinkName->GetName().GetBuffer();
		//入力したものと購入出来るものの名前を比較
		int result = std::wcscmp(wc, dWc);
		//同じ名前だった場合
		if (result == 0)
		{
			m_isDecision = true;
			break;
		}
	}
	//購入に失敗した場合
	if(!m_isDecision)
	{
		//エラーチェック
		Utility::ErrorCheck("購入に失敗しました。");
		//再帰
		DecideBuy(drink);
	}

	return wc;
}

//----------------------------------------------------------------------
//! @brief お金を受け取る
//!
//! @param[in] お金
//!
//! @return なし
//----------------------------------------------------------------------
void Buyer::ReceiveMoney(std::unique_ptr<Money> money)
{
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_moneyNum->AddMoney(i, money->GetMoney(i));
	}
	m_possessionMoney = 0;
	//所持金の計算
	for (int i = 0; i < Money::MONEYTYPE_NUM; i++)
	{
		m_possessionMoney += m_moneyNum->GetMoney(i) * m_moneyNum->GetValue(i);
	}
	cout << "貴方の所持金は" << m_possessionMoney << "円です。" << endl;

}

//----------------------------------------------------------------------
//! @brief お金の枚数をセットする
//!
//! @param[in] メッセージ、枚数を決めるお金
//!
//! @return なし
//----------------------------------------------------------------------
void Buyer::SetMoneyNum(const char * messe, int setNum)
{
	//枚数
	int num;
	//文字の表示
	Utility::DrawChara(messe);
	//枚数のセット
	cin >> num;
	//エラーチェック、もしくはマイナスの値を入力した場合、もしくは最大枚数より多い値を入力した場合
	if (cin.fail() || num < 0 || num > sMONEY_MAXNUM)
	{
		num = 0;
		Utility::ErrorCheck("不正な値です。");
		//再帰
		SetMoneyNum(messe, setNum);
	}
	//値の挿入
	m_moneyNum->AddMoney(setNum,num);
	//バッファのクリア
	Utility::ClearBuf();
}

//----------------------------------------------------------------------
//! @brief お金を支払う
//!
//! @param[in] メッセージ、所持枚数、種類
//!
//! @return なし
//----------------------------------------------------------------------
void Buyer::PayMoney(const char* messe, int payNum, int kind)
{
	//枚数
	int num;

	//文字の表示
	Utility::DrawChara(messe);
	Utility::DrawChara(payNum);
	Utility::DrawChara("枚)");

	//枚数のセット
	cin >> num;
	//エラーチェック、もしくは所持枚数より多い数字を入力した場合、もしくはマイナスの値を入力した場合
	if (cin.fail() || num > m_moneyNum->GetMoney(kind) || num < 0)
	{
		num = 0;
		Utility::ErrorCheck("不正な値です。");
		//再帰
		PayMoney(messe, payNum, kind);
	}
	//値の挿入
	m_moneyNum->DeleteMoney(kind, num);
	//支払った額
	m_amountMoney->AddMoney(kind, num);
	//バッファのクリア
	Utility::ClearBuf();

}
