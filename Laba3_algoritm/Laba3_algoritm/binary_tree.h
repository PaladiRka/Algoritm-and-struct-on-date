#pragma once
#include "node.h"

class BinaryTree
{
public:
	BinaryTree();

	BinaryTree(BinaryTree&);

	BinaryTree(BinaryTree && right);

	void addnode(node *);

	void put(int, int);

	int contain(int value);

	int get(int);

	void out();

	BinaryTree * copy();

	int getmaxkey() { return root->findmax()->getkey(); }

	int getminkey() { return root->findmin()->getkey(); }

	BinaryTree operator&(BinaryTree &);

	BinaryTree operator|(BinaryTree &);

	BinaryTree operator/(BinaryTree &);

	BinaryTree operator+(BinaryTree &);

	BinaryTree operator=(BinaryTree &);

	BinaryTree operator=(BinaryTree &&);

	BinaryTree operator*();

	BinaryTree * operator=(BinaryTree *);

	~BinaryTree();

private:

	node * root = nullptr;

};


