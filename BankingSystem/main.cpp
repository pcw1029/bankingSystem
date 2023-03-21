/*
 * main.cpp
 *
 *  Created on: 2023. 2. 24.
 *      Author: pcw1029
 */

#include<iostream>
#include<cstring>

using namespace::std;

#define NAME_LEN 20

class Account{
public:
	Account();
	Account(int _iId, int _iBalance, char* _pchName);
	~Account();

private:
	int iId;
	int iBalance;
	char *pchName;

public:
	int getId();
	int getBalance();
	char* getName();
	void deposit(int _iBalance);
	void withraw(int _iBalance);
	void showInfo();
};

Account::Account(int _iId, int _iBalance, char* _pchName)
{
	this->iId = _iId;
	this->iBalance = _iBalance;
	this->pchName = new char[strlen(_pchName)+1];
	strcpy(this->pchName, _pchName);
}

Account::~Account()
{
	delete []pchName;
}

int Account::getId()
{
	return iId;
}

int Account::getBalance()
{
	return iBalance;
}

char* Account::getName()
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

void Account::showInfo()
{
	cout<<"----- ----- ----- -----"<<endl;
	cout<<"계좌 ID : "<<iId<<endl;
	cout<<"고객 이름 : "<<pchName<<endl;
	cout<<"잔    액 :"<<iBalance<<endl;
}

int iIndex = 0;

void printMenu();
void makeAccount(Account** pcAccount);
void deposit(Account** pcAccount);
void withraw(Account** pcAccount);
void inquire(Account** pcAccount);

enum {
	EXIT = 0,
	MAKE,
	DEPOSIT,
	WITHRAW,
	INQUIRE
};

int main()
{
	int iSelect=-1;
	Account *pcAccount[100];
	while(iSelect!=0){
		printMenu();
		cin>>iSelect;
		switch(iSelect){
		case 1:
			makeAccount(pcAccount);
			break;
		case 2:
			deposit(pcAccount);
			break;
		case 3:
			withraw(pcAccount);
			break;
		case 4:
			inquire(pcAccount);
			break;
		case 0:
			cout<<"은행 계좌 관리 프로그램을 종료합니다."<<endl;
			break;
		}
	}

}

void printMenu()
{
	cout<<"##### MENU #####"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입   금"<<endl;
	cout<<"3. 출   금"<<endl;
	cout<<"4. 전체 고객 잔액 조회"<<endl;
	cout<<"0. 나가기"<<endl;
}

void makeAccount(Account** pcAccount)
{
	int iId;
	int iBalance;
	char chName[NAME_LEN];
	cout<<"##### 계좌 개설 #####"<<endl;
	cout<<"1. 계좌 ID : ";
	cin>>iId;
	cout<<"2. 이    름 : ";
	cin>>chName;
	cout<<"3. 입 금 액 : ";
	cin>>iBalance;
	pcAccount[iIndex++] = new Account(iId, iBalance, chName);
}

void deposit(Account** pcAccount)
{
	int iId, iBalance;
	int i;
	cout<<"입금 계좌 ID : ";
	cin>>iId;
	for(i=0; i<iIndex; i++){
		if(iId == pcAccount[i]->getId()){
			cout<<"입금 금액 : ";
			cin >> iBalance;
			if(iBalance<=0){
				cout<<"입금 금액은 0보다 커야합니다."<<endl;
			}else{
				pcAccount[i]->deposit(iBalance);
			}
			break;
		}
	}
	if(i == iIndex){
		cout<<"일치하는 계좌 ID("<<iId<<")가 없습니다."<<endl;
	}
}

void withraw(Account** pcAccount)
{
	int iId, iBalance;
	int i;
	cout<<"출금 계좌 ID : ";
	cin>>iId;
	for(i=0; i<iIndex; i++){
		if(iId == pcAccount[i]->getId()){
			cout<<"출금 금액 : ";
			cin >> iBalance;
			if(iBalance<=0){
				cout<<"출금 금액은 0보다 커야합니다."<<endl;
			}else if(iBalance > pcAccount[i]->getBalance()){
				cout<<"잔액이 부족합니다."<<endl;
			}else{
				pcAccount[i]->withraw(iBalance);
			}
			break;
		}
	}
	if(i == iIndex){
		cout<<"일치하는 계좌 ID("<<iId<<")가 없습니다."<<endl;
	}
}

void inquire(Account** pcAccount)
{
	cout<<"##### 전체 고객 잔액 조회 #####"<<endl;
	for(int i=0; i<iIndex; i++){
		pcAccount[i]->showInfo();
	}
}
