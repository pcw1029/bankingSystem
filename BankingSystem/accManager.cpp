/*
 * accManager.cpp
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#include "accManager.h"


#include<iostream>

using namespace::std;

#define NAME_LEN 20

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
