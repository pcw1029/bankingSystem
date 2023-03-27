/*
 * accManager.h
 *
 *  Created on: 2023. 3. 24.
 *      Author: pcw1029
 */

#ifndef ACCMANAGER_H_
#define ACCMANAGER_H_

#include "donationAcc.h"
#include "creditAcc.h"
#include "container.h"
#include "normalAcc.h"

enum {
	EXIT = 0,
	MAKE,
	DEPOSIT,
	WITHRAW,
	INQUIRE
};

class AccManager {
private:
	Container cContainer;
	int iAccountNum;

public:
	AccManager();
	void printMenu() const;
	void makeAccount();
	void deposit();
	void withraw();
	void inquire();
	int getIndex();
};



#endif /* ACCMANAGER_H_ */
