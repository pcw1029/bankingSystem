/*
 * String.h
 *
 *  Created on: 2023. 3. 27.
 *      Author: pcw1029
 */

#ifndef STRING_H_
#define STRING_H_

#include<iostream>
using namespace std;

class String{
	char* pchData;
	unsigned int iDataLen;

public:
	String();
	String(const char* _pchData);
	String(const String& cStr);
	~String();

	String& operator=(const String& cStr);
	String operator+(const String& cStr);
	String& operator+=(const String& cStr);
	bool operator==(const String& cStr);

	friend ostream& operator<<(ostream& os, const String& cStr);
	friend istream& operator>>(istream& is, String& cStr);
};


#endif /* STRING_H_ */
