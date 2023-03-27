/*
 * donationAcc.h
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#ifndef DONATIONACC_H_
#define DONATIONACC_H_

#include "account.h"


class DonationAcc : public Account
{
private:
	int iTotalDonationMoney;
public:
	DonationAcc(int _iId, int _iBalance, String cStrName);
	virtual void deposit(int _iBalance);
	virtual void showInfo() const;
};


#endif /* DONATIONACC_H_ */
