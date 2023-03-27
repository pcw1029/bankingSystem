/*
 * normalAcc.cpp
 *
 *  Created on: 2023. 3. 27.
 *      Author: pcw1029
 */

#include "normalAcc.h"
#include <iostream>

using namespace std;

NormalAcc::NormalAcc(int _iId, int _iBalance, String cStrName)\
		:Account(_iId, _iBalance, cStrName)
{
	cout<<"일반 계좌 계설"<<endl;
}

void NormalAcc::deposit(int _iBalance)
{
	Account::deposit(_iBalance);
}

void NormalAcc::showInfo() const
{
	Account::showInfo();
}
