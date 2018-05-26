#include "node.h"



node::node()
{
}

node * node::insert( int k, int value) // ������� ����� k � ������ � ������ p
{
	if (!this) return new node(k, value);
	if (k == key) { value = value; return this; }
	if (k < key)
		left = left->insert(k, value);
	else
		right = right->insert(k, value);
	return balance();
}

node * node::findmin() // ����� ���� � ����������� ������ � ������ p 
{
	return this ? (left ? left->findmin() : this) : this;
}

node * node::findmax() // ����� ���� � ������������ ������ � ������ p 
{
	return this ? (right ? right->findmax() : this) : this;
}

node * node::find(node * p, int key)
{
//	if (!p) return nullptr;
	if (p && (key > p->key))
	{
		p = p->right ? find(p->right, key) : nullptr;
	}
	if (p && (key < p->key))
	{
		p = p->left ? find(p->left, key) : nullptr;
	}
	if (!p || (key == p->key))
	{
		return p;
	}
}

node * node::copy()
{
	if (!this) return nullptr;
	node * tree = new node;
	tree->left = left->copy();
	tree->right = right->copy();
	tree->key = key;
	tree->value = value;
	return tree;
	
}

node * node::operator=(node & right)
{
	return right.copy();
}

node::~node()
{
}

unsigned char node::Height()
{
	return this ? this->height : 0;
}

int node::bfactor()
{
	return right->Height() - left->Height();
}

void node::fixheight()
{
	unsigned char hl = left->Height();
	unsigned char hr = right->Height();
	height = (hl>hr ? hl : hr) + 1;
}

node * node::rotateright() // ������ ������� ������ p
{
	node * q = left;
	left = q->right;
	q->right = this;
	fixheight();
	q->fixheight();
	return q;
}

node * node::rotateleft() // ����� ������� ������ q
{
	node * p = right;
	right = p->left;
	p->left = this;
	fixheight();
	p->fixheight();
	return p;
}

node * node::balance() // ������������ ���� p
{
	fixheight();
	if (bfactor() == 2)
	{
		if (right->bfactor() < 0)
			right = right->rotateright();
		return rotateleft();
	}
	if (bfactor() == -2)
	{
		if (left->bfactor() > 0)
			left = left->rotateleft();
		return rotateright();
	}
	return this; // ������������ �� �����
}

node * node::removemin() // �������� ���� � ����������� ������ �� ������ p
{
	if (left == nullptr)
	{
		node * buf;
		buf = right;
		delete(this);
		return buf;
	}
	left = left->removemin();
	return balance();
}

node * node::removemax() // �������� ���� � ������������ ������ �� ������ p
{
	if (right == nullptr)
	{
		node * buf;
		buf = left;
		delete(this);
		return buf;
	}
	right = right->removemax();
	return balance();
}

node * node::remove(node * p, int k) // �������� ����� k �� ������ p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		node * q = p->left;
		node * r = p->right;
		delete p;
		if (!r) return q;
		node * min = r->findmin();
		min->right = r->removemin();
		min->left = q;
		return min->balance();
	}
	return p->balance();
}

node * node::findbyvalue(int value)
{
	if (!this) return nullptr;
	if (this->value == value)
		return this;
	else
	{
		if (left)
		{
			if (node * buf = left->findbyvalue(value))
				return buf;
		}
		if (right)
		{
			if (node * buf = right->findbyvalue(value))
				return buf;
		}
	}
	return nullptr;
}

void node::out()
{
	if (!this) return;

	if (left)
	{
		left->out();
	}
	std::cout << value << '	';
	if (right)
	{
		right->out();
	}
}
