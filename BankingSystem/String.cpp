/*
 * String.cpp
 *
 *  Created on: 2023. 3. 27.
 *      Author: pcw1029
 */

#include "String.h"
#include<iostream>
#include<cstring>

using namespace std;

//디폴트 생성자의 경우
String::String()
{
	pchData = NULL;
	iDataLen = 0;
}

String::String(const char* _pchData)
{
	iDataLen = strlen(_pchData);
	pchData = new char[iDataLen];
	strcpy(pchData, _pchData);
}

//복사 생성자
String::String(const String& cStr)
{
	iDataLen = strlen(cStr.pchData);
	pchData = new char[iDataLen];
	strcpy(pchData, cStr.pchData);
}

String::~String()
{
	if(pchData != NULL)
		delete [] pchData;
	iDataLen = 0;
}

String& String::operator=(const String& cStr)
{
	this->iDataLen = cStr.iDataLen;
	if(this->pchData != NULL){
		delete [] this->pchData;
	}
	this->pchData = new char [this->iDataLen];
	strcpy(this->pchData, cStr.pchData);
	return *this;
}

String String::operator+(const String& cStr)
{
	int iLen;
	char *pchTemp;
	iLen = strlen(this->pchData) + strlen(cStr.pchData);
	pchTemp = new char[iLen];
	strcpy(pchTemp, this->pchData);
	strcat(pchTemp, cStr.pchData);
	String temp(pchTemp);
	delete [] pchTemp;

	return temp;
}

String& String::operator+=(const String& cStr)
{
	int iLen;
	char *pchTemp;
	iLen = strlen(this->pchData) + strlen(cStr.pchData);
	pchTemp = new char[iLen];
	strcpy(pchTemp, this->pchData);
	strcat(pchTemp, cStr.pchData);
	delete [] this->pchData;
	this->pchData = new char[iLen];
	strcpy(pchData, pchTemp);
	delete [] pchTemp;
	return *this;
}

bool String::operator==(const String& cStr)
{
	if(strcmp(this->pchData, cStr.pchData)==0)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const String& cStr)//cout<<String
{
	os<<cStr.pchData;
	return os;
}

istream& operator>>(istream& is, String& cStr)
{
	char chTemp[100];
	is>>chTemp;
	cStr = String(chTemp);
	return is;
}
