#include<iostream>
#include "Btree.h"

using namespace std;

void f_print(BNode* r, int indent)
{
	if (r == nullptr) return;
	f_print(r->right, indent + 3);
	for (int i = 0; i < indent; ++i)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, indent + 3);
}


BNode* f_preleftmost(BNode* r, BNode* p, int a, int& m)
{
	if (p->right != nullptr)
	{
		--a;
		r = f_preleftmost(r, p->right, a, m);
		++a;
	}

	if (p->left != nullptr)
	{
		++a;
		if (m <= a)
		{
			m = a;
			r = p;
		}
		r = f_preleftmost(r, p->left, a, m);
		--a;
	}
	return r;
}

BNode* f_preleftleaf(BNode* r, BNode* p, int a, int& m)
{
	if (p->right != nullptr)
	{
		--a;
		if (p->right->left == nullptr && p->right->right == nullptr && m <= a)
		{
			m = a;
			r = p;
		}
		r = f_preleftleaf(r, p->right, a, m);
		++a;
	}

	if (p->left != nullptr)
	{
		++a;
		if (p->left->left == nullptr && p->left->right == nullptr && m <= a)
		{
			m = a;
			r = p;
		}
		r = f_preleftleaf(r, p->left, a, m);
		--a;
	}
	return r;
}

BNode* f_second_from_left_leaf(BNode* r, BNode* p, BNode* l, int a, int& m)
{
	if (p->right != nullptr)
	{
		--a;
		if (p->right->left == nullptr && p->right->right == nullptr && m <= a && p->right != l)
		{
			m = a;
			r = p->right;
		}
		r = f_second_from_left_leaf(r, p->right, l, a, m);
		++a;
	}

	if (p->left != nullptr)
	{
		++a;
		if (p->left->left == nullptr && p->left->right == nullptr && m <= a && p->left != l)
		{
			m = a;
			r = p->left;
		}
		r = f_second_from_left_leaf(r, p->left, l, a, m);
		--a;
	}
	return r;
}

void BTree::print()
{
	f_print(root);
}

BNode* BTree::leftmost()
{
	return preleftmost()->left;
}

BNode* BTree::preleftmost()
{
	int m = 0;
	BNode* p = root;
	BNode* r = nullptr;
	return f_preleftmost(r, p, 0, m);
}

void BTree::delleftmost()
{
	BNode* p = preleftmost();
	BNode* d = p->left;
	p->left = p->left->right;
	delete d;
	
}

void BTree::putleft(int d)
{
	leftmost()->left = new BNode(d);
}

BNode* BTree::leftleaf()
{
	if (preleftleaf()->left != nullptr)
	{
		return preleftleaf()->left;
	}
	else
	{
		return preleftleaf()->right;
	}
}
	

BNode* BTree::preleftleaf()
{
	int m = 0;
	BNode* p = root;
	BNode* r = nullptr;
	return f_preleftleaf(r, p, 0, m);
}

void BTree::delleftleaf()
{
	BNode* p = preleftleaf();
	if (p->left != nullptr)
	{
		p->left = nullptr;
		BNode* d = p->left;
		delete d;
	}
	else
	{
		p->right = nullptr;
		BNode* d = p->right;
		delete d;
	}
	
}

BNode* BTree::second_from_left_leaf()
{
	int m = -10;
	BNode* p = root;
	BNode* r = nullptr;
	return f_second_from_left_leaf(r, p, leftleaf(), 0, m);
}


