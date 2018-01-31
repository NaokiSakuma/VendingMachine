//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Main.cpp
//!
//! @brief  ���C�����̃\�[�X�t�@�C��
//!
//! @date   2018/01/30
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//�C���N���[�h
#include <iostream>
#include <string>
#include "Buyer.h"
#include "VendingMachine.h"

//main��
int main()
{
	//���{��̐ݒ�
	setlocale(LC_ALL, "japanese");
	//�����l
	Buyer buyer;
	//�����̔��@
	VendingMachine vendingMachine;
	buyer.Initialize();
	vendingMachine.Initialize();
	//����������
	buyer.PutInMoney();

	//�������󂯎��
	vendingMachine.ReceiveMoney(buyer.GetAmountMoney());
	//�̔����Ă�����̂�\��
	vendingMachine.ShowAllKind();
	//�������ǂ���
	buyer.IsBuy();
	//�����Ȃ�
	if (buyer.GetIsBuy())
	{
		//�h�����N�̎擾
		std::vector<CDrink*> drink;
		for (int i = 0; i < VendingMachine::DRINKTYPE_NUM; i++)
		{
			drink.push_back(vendingMachine.GetDrinkCopy(i));
		}
		//�h�����N�𔃂�
		vendingMachine.DischargeDrink(buyer.DecideBuy(drink));
		vendingMachine.Calculate();
		buyer.ReceiveMoney(vendingMachine.GetChange());
	}
	//����Ȃ��Ȃ�
	else
	{
		vendingMachine.ToChange();
		buyer.ReceiveMoney(vendingMachine.GetChange());
	}
	system("PAUSE");
	return 0;
}