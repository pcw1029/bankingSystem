/*
 * creditAcc.cpp
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#include "creditAcc.h"
#include<iostream>

using namespace::std;

CreditAcc::CreditAcc(int _iId, int _iBalance, char* _pchName) \
		:Account(_iId, (_iBalance*0.01)+_iBalance, _pchName){
	cout<<"신용 계좌 계설"<<endl;
}

void CreditAcc::deposit(int _iBalance)
{
	Account::deposit(_iBalance +(_iBalance*0.01));
}

