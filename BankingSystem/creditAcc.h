/*
 * creditAcc.h
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#ifndef CREDITACC_H_
#define CREDITACC_H_

#include "account.h"


class CreditAcc : public Account
{
public:
	CreditAcc(int _iId, int _iBalance, char* _pchName);
	virtual void deposit(int iBalance);
};


#endif /* CREDITACC_H_ */
