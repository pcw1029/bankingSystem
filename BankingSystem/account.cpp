/*
 * account.cpp
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#include "account.h"
#include<cstring>
#include<iostream>

using namespace::std;

Account::Account()
{
	iId = 0;
	iBalance = 0;
	pchName = new char[strlen("no_name")];
	strcpy(pchName, "no_name");
}

Account::Account(int _iId, int _iBalance, char* _pchName)
{
	this->iId = _iId;
	this->iBalance = _iBalance;
	this->pchName = new char[strlen(_pchName)+1];
	strcpy(this->pchName, _pchName);
}

Account::Account(const Account& cAccount)
{
	this->iId = cAccount.iId;
	this->iBalance = cAccount.iBalance;
	this->pchName = new char[strlen(cAccount.pchName)+1];
	strcpy(this->pchName, cAccount.pchName);
}

Account::~Account()
{
	delete []pchName;
}

Account& Account::operator =(const Account &cAccount)
{
	delete [] this->pchName;
	this->pchName = new char[strlen(cAccount.pchName)];
	strcpy(this->pchName, cAccount.pchName);
	this->iBalance = cAccount.iBalance;
	this->iId = cAccount.iId;
	return *this;
}

int Account::getId() const
{
	return iId;
}

int Account::getBalance() const
{
	return iBalance;
}

const char* Account::getName() const
{
	return pchName;
}

void Account::deposit(int _iBalance)
{
	iBalance += _iBalance;
}

void Account::withraw(int _iBalance)
{
	iBalance -= _iBalance;
}

void Account::showInfo() const
{
	cout<<"----- ----- ----- -----"<<endl;
	cout<<"계좌 ID : "<<iId<<endl;
	cout<<"고객 이름 : "<<pchName<<endl;
	cout<<"잔    액 :"<<iBalance<<endl;
}
