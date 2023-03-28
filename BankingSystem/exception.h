/*
 * exception.h
 *
 *  Created on: 2023. 3. 28.
 *      Author: pcw1029
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include<iostream>

using namespace std;

class ExceptionDeposit{
private:
	int iExceptionValue;

public:
	ExceptionDeposit(int iVal){
		iExceptionValue = iVal;
	}
	void showInfo(){
		cout<<"입 출금 금액 "<<iExceptionValue<<"은 유효하지 않습니다."<<endl;
	}
};

class ExceptionWithraw{
private:
	int iExceptionValue;

public:
	ExceptionWithraw(int iVal){
		iExceptionValue = iVal;
	}
	void showInfo(){
		cout<<"입 출금 금액 "<<iExceptionValue<<"은 유효하지 않습니다."<<endl;
	}
};


#endif /* EXCEPTION_H_ */
