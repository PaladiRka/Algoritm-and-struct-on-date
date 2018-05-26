#pragma once
#include "intHashMap.h"
#include "stdio.h"
#include "string.h"

class HashMapSequence : IntHashMap
{
public:
	HashMapSequence();

	void put(int, int);

	int get(int);

	int rand_value();

	int getCurrent() { return currentNumber; }

	void set(int , int );

	HashMapSequence EXCL(HashMapSequence & right);

	HashMapSequence ERASE(int p1, int p2);

	void CHANGE(HashMapSequence & right, int p1);

	~HashMapSequence();
private:

	int numbers[1000] ;

	int currentNumber = 0;

};

