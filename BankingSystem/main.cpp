/*
 * main.cpp
 *
 *  Created on: 2023. 2. 24.
 *      Author: pcw1029
 */

#include<iostream>

using namespace::std;

#define NAME_LEN 20

typedef struct {
	int iId;
	int iBalance;
	char chName[NAME_LEN];
}Account;

Account g_astAccount[100];
int iIndex = 0;

void printMenu();
void makeAccount();
void deposit();
void withraw();
void inquire();

enum {
	EXIT = 0,
	MAKE = 1,
	DEPOSIT,
	WITHRAW,
	INQUIRE
};

int main()
{
	int iSelect;
	while(1){
		printMenu();
		cin>>iSelect;
		switch(iSelect){
		case 1:
			makeAccount();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withraw();
			break;
		case 4:
			inquire();
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

void makeAccount()
{
	cout<<"##### 계좌 개설 #####"<<endl;
	cout<<"1. 계좌 ID : ";
	cin>>g_astAccount[iIndex].iId;
	cout<<"2. 이    름 : ";
	cin>>g_astAccount[iIndex].chName;
	cout<<"3. 입 금 액 : ";
	cin>>g_astAccount[iIndex].iBalance;
	iIndex++;
}

void deposit()
{
	int iId, iBalance;
	int i;
	cout<<"입금 계좌 ID : ";
	cin>>iId;
	for(i=0; i<iIndex; i++){
		cout<<"deposit() "<<__LINE__<<endl;
		if(iId == g_astAccount[i].iId){
			cout<<"입금 금액 : ";
			cin >> iBalance;
			cout<<"deposit() "<<__LINE__<<endl;
			if(iBalance<=0){
				cout<<"입금 금액은 0보다 커야합니다."<<endl;
			}else{
				g_astAccount[i].iBalance += iBalance;
			}
			cout<<"deposit() "<<__LINE__<<endl;
			break;
		}
	}
	cout<<"deposit() "<<__LINE__<<endl;
	if(i == iIndex){
		cout<<"일치하는 계좌 ID("<<iId<<")가 없습니다."<<endl;
	}
	cout<<"deposit() "<<__LINE__<<endl;
}

void withraw()
{
	int iId, iBalance;
	int i;
	cout<<"출금 계좌 ID : ";
	cin>>iId;
	for(i=0; i<iIndex; i++){
		if(iId == g_astAccount[i].iId){
			cout<<"출금 금액 : ";
			cin >> iBalance;
			if(iBalance<=0){
				cout<<"출금 금액은 0보다 커야합니다."<<endl;
			}else{
				if(iBalance > g_astAccount[i].iBalance){
					cout<<"잔액이 부족합니다."<<endl;
				}else{
					g_astAccount[i].iBalance -= iBalance;
				}
			}
			break;
		}
	}
	if(i == iIndex){
		cout<<"일치하는 계좌 ID("<<iId<<")가 없습니다."<<endl;
	}
}

void inquire()
{
	cout<<"##### 전체 고객 잔액 조회 #####"<<endl;
	for(int i=0; i<iIndex; i++){
		cout<<"계좌 ID : "<<g_astAccount[i].iId<<endl;
		cout<<"고객 이름 : "<<g_astAccount[i].chName<<endl;
		cout<<"잔    액 :"<<g_astAccount[i].iBalance<<endl;
	}
}
