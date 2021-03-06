//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Money.h
//!
//! @brief  ¨ΰNXΜwb_t@C
//!
//! @date   2018/01/26
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

//¨ΰNX
class Money
{
public:
	//RXgN^
	Money();
	//fXgN^
	~Money() {}
	//¨ΰΜέΙΜΗΑ
	void AddMoney(int kind, int addNum);
	//¨ΰΜέΙΜν
	void DeleteMoney(int kind, int deleteNum);
	//¨ΰΜέΙΜgetter
	int GetMoney(int kind);
	//¨ΰΜΏlΜgetter
	int GetValue(int& kind);
	//¨ΰπZbg·ι
	void Reset();
	//¨ΰΜνή
	enum MoneyType
	{
		BILL1000,     //1000~D
		COIN500,	  //500~Κ
		COIN100,	  //100~Κ
		COIN50,		  //50~Κ
		COIN10,		  //10~Κ
		MONEYTYPE_NUM //dέΜνήΜ
	};
#pragma region Constant
	//1000~DΜΏl
	static const int sBILL1000_VALUE;
	//500~ΚΜΏl
	static const int sCOIN500_VALUE;
	//100~ΚΜΏl
	static const int sCOIN100_VALUE;
	//50~ΚΜΏl
	static const int sCOIN50_VALUE;
	//10~ΚΜΏl
	static const int sCOIN10_VALUE;
#pragma endregion

private:
	//¨ΰΜέΙ
	int m_moneyStock[MONEYTYPE_NUM];
	//¨ΰΜΏl
	int m_value[MONEYTYPE_NUM];
};