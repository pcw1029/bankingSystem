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

enum {
	EXIT = 0,
	MAKE,
	DEPOSIT,
	WITHRAW,
	INQUIRE
};

class Account{
public:
	Account();
	Account(int _iId, int _iBalance, char* _pchName);
	Account(const Account& cAccount);
	virtual ~Account();

private:
	int iId;
	int iBalance;
	char *pchName;

public:
	int getId() const;
	int getBalance() const;
	const char* getName() const;
	virtual void deposit(int _iBalance);
	void withraw(int _iBalance);
	virtual void showInfo() const;
};

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


class CreditAcc : public Account
{
public:
	CreditAcc(int _iId, int _iBalance, char* _pchName);
	virtual void deposit(int iBalance);
};

CreditAcc::CreditAcc(int _iId, int _iBalance, char* _pchName) \
		:Account(_iId, (_iBalance*0.01)+_iBalance, _pchName){
	cout<<"신용 계좌 계설"<<endl;
}

void CreditAcc::deposit(int _iBalance)
{
	Account::deposit(_iBalance +(_iBalance*0.01));
}


class DonationAcc : public Account
{
private:
	int iTotalDonationMoney;
public:
	DonationAcc(int _iId, int _iBalance, char* _pchName);
	virtual void deposit(int _iBalance);
	virtual void showInfo() const;
};

DonationAcc::DonationAcc(int _iId, int _iBalance, char* _pchName) \
		: Account(_iId, _iBalance, _pchName)
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

class AccManager {
private:
	int iIndex;
	Account *pcAccount[100];


public:
	AccManager();
	~AccManager(){
		for(int i=0; i<iIndex; i++){
			delete [] pcAccount[i];
		}
	}

public:
	void printMenu() const;
	void makeAccount();
	void deposit();
	void withraw();
	void inquire() const;
	int getIndex() const;
};

AccManager::AccManager(){
	iIndex = 0;
}

void AccManager::printMenu() const
{
	cout<<"##### MENU #####"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입   금"<<endl;
	cout<<"3. 출   금"<<endl;
	cout<<"4. 전체 고객 잔액 조회"<<endl;
	cout<<"0. 나가기"<<endl;
}

void AccManager::makeAccount()
{
	int iId;
	int iBalance;
	int iSelectKindOfAccount;
	char chName[NAME_LEN];
	cout<<"##### 계좌 개설 #####"<<endl;
	cout<<"1. 신용계좌"<<endl;
	cout<<"2. 기부계좌"<<endl;
	cout<<"계좌개서 종류 선택 : ";
	cin>>iSelectKindOfAccount;
	if(iSelectKindOfAccount < 0 || iSelectKindOfAccount > 2){
		cout<<"계좌개설 종류 선택이 잘못되었습니다. 다시 진행해 주세요."<<endl;
		return;
	}
	cout<<"1. 계좌 ID : ";
	cin>>iId;
	cout<<"2. 이    름 : ";
	cin>>chName;
	cout<<"3. 입 금 액 : ";
	cin>>iBalance;
	if(iSelectKindOfAccount == 1)
		pcAccount[iIndex++] = new CreditAcc(iId, iBalance, chName);
	else
		pcAccount[iIndex++] = new DonationAcc(iId, iBalance, chName);

}

void AccManager::deposit()
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

void AccManager::withraw()
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

void AccManager::inquire() const
{
	cout<<"##### 전체 고객 잔액 조회 #####"<<endl;
	for(int i=0; i<iIndex; i++){
		pcAccount[i]->showInfo();
	}
}




int main()
{
	int iSelect=-1;
	AccManager cAccManager;
	while(iSelect!=0){
		cAccManager.printMenu();
		cin>>iSelect;
		switch(iSelect){
		case 1:
			cAccManager.makeAccount();
			break;
		case 2:
			cAccManager.deposit();
			break;
		case 3:
			cAccManager.withraw();
			break;
		case 4:
			cAccManager.inquire();
			break;
		case 0:
			cout<<"은행 계좌 관리 프로그램을 종료합니다."<<endl;
			break;
		}
	}

}

