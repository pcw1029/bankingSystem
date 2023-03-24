/*
 * account.h
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

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

#endif /* ACCOUNT_H_ */
