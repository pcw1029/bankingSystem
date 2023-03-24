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

enum {
	EXIT = 0,
	MAKE,
	DEPOSIT,
	WITHRAW,
	INQUIRE
};

class AccManager {
private:
	int iIndex;
	Account *pcAccount[100];


public:
	AccManager();
	~AccManager(){
		for(int i=0; i<iIndex; i++){
			delete [] pcAccount[i];
		}
	}

public:
	void printMenu() const;
	void makeAccount();
	void deposit();
	void withraw();
	void inquire() const;
	int getIndex() const;
};



#endif /* ACCMANAGER_H_ */
