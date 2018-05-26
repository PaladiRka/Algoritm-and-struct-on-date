#pragma once
#include <iostream>

class node
{
public:
	node();

	node(int k, int value) { key = k; left = right = nullptr; this->value = value; }

	node * insert(int , int );	// ������� ����� k � ������ � ������ p

	node * findmin();			// ����� ���� � ����������� ������ � ������ p 
		
	node * findmax();			// ����� ���� � ������������ ������ � ������ p

	node * find(node * , int );	// ����� ���� � ������ key � ������ p

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

	node * rotateright();	// ������ ������� ������ p

	node * rotateleft();	// ����� ������� ������ q

	node * balance();		// ������������ ���� p

	node * removemin();		// �������� ���� � ����������� ������ �� ������ p

	node * removemax();

	node * remove(node * , int );	// �������� ����� k �� ������ p
};

