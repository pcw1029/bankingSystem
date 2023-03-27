/*
 * container.h
 *
 *  Created on: 2023. 3. 26.
 *      Author: pcw1029
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_
#include "account.h"

typedef Account* Element;

class Container{
private:
	Element *array;
	int length;
	int arrIndex;

public:
	Container(int len=100);
	~Container();
	void insert(Element data);
	Element remove(int idx);

	Element getItem(int idx);
	int getElementTotCount(){
		return arrIndex;
	}
};


#endif /* CONTAINER_H_ */
