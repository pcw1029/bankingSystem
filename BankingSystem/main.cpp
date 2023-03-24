/*
 * main.cpp
 *
 *  Created on: 2023. 2. 24.
 *      Author: pcw1029
 */

#include<iostream>
#include "accManager.h"

using namespace::std;

int main()
{
	int iSelect=-1;
	AccManager cAccManager;
	while(iSelect!=0){
		cAccManager.printMenu();
		cin>>iSelect;
		switch(iSelect){
		case MAKE:
			cAccManager.makeAccount();
			break;
		case DEPOSIT:
			cAccManager.deposit();
			break;
		case WITHRAW:
			cAccManager.withraw();
			break;
		case INQUIRE:
			cAccManager.inquire();
			break;
		case EXIT:
			cout<<"은행 계좌 관리 프로그램을 종료합니다."<<endl;
			break;
		}
	}

}

