/*
 * container.h
 *
 *  Created on: 2023. 3. 26.
 *      Author: pcw1029
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_
#include "account.h"

template <typename T>
class Container{
private:
	T *templateArray;
//	Element *array;
	int length;
	int arrIndex;

public:
	Container(int len=100);
	~Container();
	void insert(T data);
	T remove(int idx);

	T getItem(int idx);
	int getElementTotCount(){
		return arrIndex;
	}
};

template <typename T>
Container<T>::Container(int len) : arrIndex(0)
{
	if(len <= 0)
		len = 50;
	length = len;
	templateArray = new T[length];
}

template <typename T>
Container<T>::~Container()
{
	delete [] templateArray;
}

template <typename T>
void Container<T>::insert(T data)
{
	if(arrIndex >= length){
		cout<<"저장공간이 부족합니다."<<endl;
		return;
	}
	templateArray[arrIndex++] = data;
}

template <typename T>
T Container<T>::remove(int idx)
{
	int iIndex;
	if(idx < 0 || idx > length){
		cout<<"존재하지 않는 요소입니다."<<endl;
		return NULL;
	}

	T del = templateArray[idx];
	for(iIndex=idx; iIndex<arrIndex; iIndex++){
		templateArray[iIndex] = templateArray[iIndex+1];
	}
	arrIndex--;
	return del;
}

template <typename T>
T Container<T>::getItem(int idx)
{
	if(idx < 0 || idx > length){
		cout<<"존재하지 않는 요소입니다."<<endl;
		return NULL;
	}
	return templateArray[idx];
}


#endif /* CONTAINER_H_ */
