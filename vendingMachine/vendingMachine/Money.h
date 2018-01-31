//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Money.h
//!
//! @brief  お金クラスのヘッダファイル
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//お金クラス
class Money
{
public:
	//コンストラクタ
	Money();
	//デストラクタ
	~Money() {}
	//お金の在庫の追加
	void AddMoney(int kind, int addNum);
	//お金の在庫の削除
	void DeleteMoney(int kind, int deleteNum);
	//お金の在庫のgetter
	int GetMoney(int kind);
	//お金の価値のgetter
	int GetValue(int& kind);
	//お金をリセットする
	void Reset();
	//お金の種類
	enum MoneyType
	{
		BILL1000,     //1000円札
		COIN500,	  //500円玉
		COIN100,	  //100円玉
		COIN50,		  //50円玉
		COIN10,		  //10円玉
		MONEYTYPE_NUM //硬貨の種類の数
	};
#pragma region Constant
	//1000円札の価値
	static const int sBILL1000_VALUE;
	//500円玉の価値
	static const int sCOIN500_VALUE;
	//100円玉の価値
	static const int sCOIN100_VALUE;
	//50円玉の価値
	static const int sCOIN50_VALUE;
	//10円玉の価値
	static const int sCOIN10_VALUE;
#pragma endregion

private:
	//お金の在庫
	int m_moneyStock[MONEYTYPE_NUM];
	//お金の価値
	int m_value[MONEYTYPE_NUM];
};