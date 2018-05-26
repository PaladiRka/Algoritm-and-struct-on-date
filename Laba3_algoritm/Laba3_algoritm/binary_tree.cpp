#include "binary_tree.h"

BinaryTree::BinaryTree()
{
}

BinaryTree::BinaryTree(BinaryTree & right)
{
	this->root = right.root->copy();
}

BinaryTree::BinaryTree(BinaryTree && right)
{
	this->root = right.root->copy();
}

void BinaryTree::addnode(node * nodeforadd)
{
	if (nodeforadd)	root->insert(root ? root->findmax()->getkey() + 1 : 1, nodeforadd->getvalue());
}

void BinaryTree::put(int key, int value)
{
	if (contain(value) == -1)
		root = root->insert(key, value);
}

int BinaryTree::contain(int value)
{
	return root->findbyvalue(value) ? 1 : -1;
}

int BinaryTree::get(int key)
{
	return root->find(root, key)->getvalue();
}

void BinaryTree::out()
{
	root->out();
}

BinaryTree * BinaryTree::copy()
{
	BinaryTree * newtree = new BinaryTree;
	newtree->root = root->copy();
	return newtree;
}

BinaryTree BinaryTree::operator&(BinaryTree & right)
{
	BinaryTree newtree;
	for (int i = getminkey(); i < getmaxkey() + 1; i++)
	{
		if (node * finder = root->find(root, i)) 
		{	// берём элемент из левого
			// если нашли элемент с таким же value в правом записываем в ответ
			if (node * buf = right.root->findbyvalue(finder->getvalue()))
				newtree.put(buf->getkey(), buf->getvalue()); 
		}
	}
	return newtree;
}

BinaryTree BinaryTree::operator|(BinaryTree & right)
{
	BinaryTree newtree;
	for (int i = 1; i < (getmaxkey() > right.getmaxkey() ? getmaxkey() : right.getmaxkey()); i++)
	{
		newtree.put(root->find(root, i)->getkey(), root->find(root, i)->getvalue());
		newtree.put(right.root->find(right.root, i)->getkey(), right.root->find(right.root, i)->getvalue());
	}
	return newtree;
}

BinaryTree BinaryTree::operator+(BinaryTree & right)
{
	BinaryTree newtree;
	for (int i = getminkey(); i < getmaxkey() + 1; i++)
	{
		if (node * finder = root->find(root, i))
		{	// берём элемент из левого
			// если не нашли элемент с таким же value в правом записываем в ответ
			if (!(right.root->findbyvalue(finder->getvalue())))
				newtree.put(finder->getkey(), finder->getvalue());
		}
	}
	for (int i = right.getminkey(); i < right.getmaxkey() + 1; i++)
	{
		if (node * finder = right.root->find(right.root, i))
		{	// берём элемент из правого
			// если не нашли элемент с таким же value в левом записываем в ответ
			if (!(root->findbyvalue(finder->getvalue())))
				newtree.put(finder->getkey(), finder->getvalue());
		}
	}
	return newtree;
}

BinaryTree BinaryTree::operator/(BinaryTree & right)
{
	BinaryTree newtree;
	for (int i = getminkey(); i < getmaxkey() + 1; i++)
	{
		if (node * finder = root->find(root, i))
		{	// берём элемент из левого
			// если не нашли элемент с таким же value в правом записываем в ответ
			if (!(right.root->findbyvalue(finder->getvalue())))
				newtree.put(finder->getkey(), finder->getvalue());
		}
	}
	return newtree;
}

BinaryTree BinaryTree::operator=(BinaryTree & right)
{
	return *right.copy();
}

BinaryTree BinaryTree::operator=(BinaryTree && right)
{
	this->root = right.root->copy();
	return *this;
}

BinaryTree BinaryTree::operator*()
{
	BinaryTree newtree;
	newtree.root = root;
	return newtree;
}

BinaryTree * BinaryTree::operator=(BinaryTree * right)
{
	return right->copy();
}

BinaryTree::~BinaryTree()
{
}