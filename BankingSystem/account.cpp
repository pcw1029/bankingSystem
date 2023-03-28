/*
 * account.cpp
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#include "account.h"
#include "exception.h"
#include<cstring>
#include<iostream>

using namespace::std;
Account::Account(int _iId, int _iBalance, String _cStrName)
{
	this->iId = _iId;
	this->iBalance = _iBalance;
	this->cStrName = _cStrName;
}

int Account::getId() const
{
	return iId;
}

int Account::getBalance() const
{
	return iBalance;
}

const String& Account::getName() const
{
	return cStrName;
}

void Account::deposit(int _iBalance)
{
	if(_iBalance <= 0){
		throw ExceptionDeposit(_iBalance);
	}
	iBalance += _iBalance;
}

void Account::withraw(int _iBalance)
{
	if(_iBalance <= 0){
		throw ExceptionDeposit(_iBalance);
	}else if(_iBalance > this->iBalance){
		throw ExceptionWithraw(_iBalance);
	}
	iBalance -= _iBalance;
}

void Account::showInfo() const
{
	cout<<"----- ----- ----- -----"<<endl;
	cout<<"계좌 ID : "<<iId<<endl;
	cout<<"고객 이름 : "<<cStrName<<endl;
	cout<<"잔    액 :"<<iBalance<<endl;
}
