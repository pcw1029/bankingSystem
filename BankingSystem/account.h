/*
 * account.h
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "String.h"
class Account{
public:
	Account(int _iId, int _iBalance, String _cStrName);
private:
	int iId;
	int iBalance;
	String cStrName;

public:
	int getId() const;
	int getBalance() const;
	const String& getName() const;
	virtual void deposit(int _iBalance);
	void withraw(int _iBalance);
	virtual void showInfo() const;
};

#endif /* ACCOUNT_H_ */
