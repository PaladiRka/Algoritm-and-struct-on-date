#pragma once
#include <iostream>

class node
{
public:
	node();

	node(int k, int value) { key = k; left = right = nullptr; this->value = value; }

	node * insert(int , int );	// вставка ключа k в дерево с корнем p

	node * findmin();			// поиск узла с минимальным ключом в дереве p 
		
	node * findmax();			// поиск узла с максимальным ключом в дереве p

	node * find(node * , int );	// поиск узла с ключом key в дереве p

	node * copy();

	node * operator=(node &);

	node * findbyvalue(int );

	void out();

	int getkey() { return this ? key : 0; }

	int getvalue() { return this ? value : 0; }
	
	node * getleft() { return left; }

	node * getright() { return right; }

	unsigned char Height();

	~node();
private:

	int key;

	int value;

	unsigned char height;

	node * left = nullptr;

	node * right = nullptr;

	int bfactor();

	void fixheight();

	node * rotateright();	// правый поворот вокруг p

	node * rotateleft();	// левый поворот вокруг q

	node * balance();		// балансировка узла p

	node * removemin();		// удаление узла с минимальным ключом из дерева p

	node * removemax();

	node * remove(node * , int );	// удаление ключа k из дерева p
};

