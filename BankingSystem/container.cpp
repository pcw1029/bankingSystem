/*
 * container.cpp
 *
 *  Created on: 2023. 3. 26.
 *      Author: pcw1029
 */

#include <iostream>
#include "container.h"

using namespace std;

Container::Container(int len) : arrIndex(0)
{
	if(len <= 0)
		len = 50;
	length = len;
	array = new Element[length];

}

Container::~Container()
{
	delete [] array;
}

void Container::insert(Element data)
{
	if(arrIndex >= length){
		cout<<"저장공간이 부족합니다."<<endl;
		return;
	}
	array[arrIndex++] = data;
}

Element Container::remove(int idx)
{
	int iIndex;
	if(idx < 0 || idx > length){
		cout<<"존재하지 않는 요소입니다."<<endl;
		return NULL;
	}

	Element del = array[idx];
	for(iIndex=idx; iIndex<arrIndex; iIndex++){
		array[iIndex] = array[iIndex+1];
	}
	arrIndex--;
	return del;
}

Element Container::getItem(int idx)
{
	if(idx < 0 || idx > length){
		cout<<"존재하지 않는 요소입니다."<<endl;
		return NULL;
	}
	return array[idx];
}

