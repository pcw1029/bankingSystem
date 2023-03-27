/*
 * donationAcc.cpp
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#include "donationAcc.h"
#include<iostream>

using namespace::std;


DonationAcc::DonationAcc(int _iId, int _iBalance, String cStrName) \
		: Account(_iId, _iBalance, cStrName)
{
	cout<<"기부 계좌 계설"<<endl;
	iTotalDonationMoney = _iBalance*0.01;
}

void DonationAcc::deposit(int _iBalance)
{
	Account::deposit(_iBalance);
	iTotalDonationMoney += (_iBalance * 0.01);
}

void DonationAcc::showInfo() const
{
	Account::showInfo();
	cout<<"총 기부 금액 : "<<iTotalDonationMoney<<endl;
}
