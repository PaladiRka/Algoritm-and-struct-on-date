#pragma once
#include <cstdlib>

class IntHashMap
{
public:
	IntHashMap();

	void put(int , int );

	int get(int );

	int rand_value();

	

	IntHashMap operator*(IntHashMap & );

	IntHashMap operator/(IntHashMap & );

	IntHashMap operator+(IntHashMap & );

	IntHashMap operator|(IntHashMap );

	int contain(int );

	~IntHashMap();

private:
	static const int MAXINT = 32;

	static const int M = 100;

	static const int A = 97;

	static const int B = 11;

	int hash_func(int );

	int map[M] = { 0 };

	int get_empty_key();

	int peek(int );
};

