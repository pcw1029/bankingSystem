/*
 * normalAcc.h
 *
 *  Created on: 2023. 3. 27.
 *      Author: pcw1029
 */

#ifndef NORMALACC_H_
#define NORMALACC_H_

#include"account.h"

class NormalAcc : public Account{
public:
	NormalAcc(int _iId, int _iBalance, String cStrName);
	virtual void deposit(int _iBalance);
	virtual void showInfo() const;
};


#endif /* NORMALACC_H_ */
