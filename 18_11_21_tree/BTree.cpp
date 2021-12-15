#include<iostream>
#include "Btree.h"

using namespace std;

BTree::~BTree()
{
	f_del(root);
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

int BTree::count()
{
	return f_count(root);
}

void BTree::scale()
{
	f_scale(root);
}

int BTree::sum()
{
	return f_sum(root);
}

int BTree::count_neg()
{
	return f_count_neg(root);
}

int BTree::height()
{
	int m = -1;
	if (root == nullptr)
	{
		return 0;
	}
	return f_height(root, 1, m);
}

void BTree::reflect()
{
	f_reflect(root);
}

int BTree::mult()
{
	return f_mult(root);
}

int BTree::eval()
{
	return f_eval(root);
}

void BTree::del0()
{
	f_del0(root);
}

void BTree::delLeaves()
{
	f_delLeaves(root);
}

void BTree::enlarge(int d)
{
	f_enlarge(root, d);
}

void BTree::del1()
{
	f_del1(root);
}

int BTree::sum_alt()
{
	return f_sum_alt(root->left, 0) + f_sum_alt(root->right, 0);
}

BNode* BTree::find_rec(int d)
{
	return f_find_rec(root, d);
}

BNode* BTree::find_cycle(int d)
{
	return f_find_cycle(root, d);
}

void BTree::insert_rec(int d)
{
	f_insert_rec(root, d);
}

void BTree::insert_cycle(int d)
{
	f_insert_cycle(root, d);
}

////////////////////////////////

void BTree::f_del(BNode*& p)
{
	if (p == nullptr)
	{
		return;
	}
	f_del(p->left);
	f_del(p->right);
	delete p;
	p = nullptr;
}

void BTree::f_print(BNode* r, int indent)
{
	if (r == nullptr) return;
	f_print(r->right, indent + 3);
	for (int i = 0; i < indent; ++i)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, indent + 3);
}

BNode* BTree::f_preleftmost(BNode* r, BNode* p, int a, int& m)
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

BNode* BTree::f_preleftleaf(BNode* r, BNode* p, int a, int& m)
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

BNode* BTree::f_second_from_left_leaf(BNode* r, BNode* p, BNode* l, int a, int& m)
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

int BTree::f_count(BNode* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	return 1 + f_count(p->left) + f_count(p->right);
}

void BTree::f_scale(BNode* p)
{
	if (p == nullptr)
	{
		return;
	}
	p->data *= 3;
	f_scale(p->left);
	f_scale(p->right);
}

int BTree::f_sum(BNode* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	return p->data + f_sum(p->left) + f_sum(p->right);
}

int BTree::f_count_neg(BNode* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	if (p->data < 0)
	{
		return 1 + f_count_neg(p->left) + f_count_neg(p->right);
	}
	return f_count_neg(p->left) + f_count_neg(p->right);
}
 
int BTree::f_height(BNode* p, int h , int& m)
{
	if (p->left != nullptr)
	{
		++h;
		f_height(p->left, h, m);
		--h;
	}
	if (p->right != nullptr)
	{
		++h;
		f_height(p->right, h, m);
		--h;
	}
	if (m <= h)
	{
		m = h;
	}
	return m;
}

void BTree::f_reflect(BNode* p)
{
	if (p == nullptr)
	{
		return;
	}
	BNode* q = p->left;
	p->left = p->right;
	p->right = q;
	f_reflect(p->left);
	f_reflect(p->right);
}

int BTree::f_mult(BNode* p)
{
	if (p == nullptr)
	{
		return 1;
	}
	if (p->left != nullptr && p->right != nullptr)
	{
		return p->data * f_mult(p->right) * f_mult(p->left);
	}
	return f_mult(p->right) * f_mult(p->left);
}

int BTree::f_eval(BNode* p)
{
	if (p->left->left == nullptr && p->right->right == nullptr) 
	{
		switch (p->data)
		{
		case 1 :
		{
			return p->left->data + p->right->data;
			break;
		}
		case 2:
		{
			return p->left->data - p->right->data;
			break;
		}
		case 3:
		{
			return p->left->data * p->right->data;
			break;
		}
		case 4:
		{
			return p->left->data / p->right->data;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	
	if (p->left->left == nullptr && p->right->right != nullptr)
	{
		switch (p->data)
		{
		case 1:
		{
			return p->left->data + f_eval(p->right);
			break;
		}
		case 2:
		{
			return p->left->data - f_eval(p->right);
			break;
		}
		case 3:
		{
			return p->left->data * f_eval(p->right);
			break;
		}
		case 4:
		{
			return p->left->data / f_eval(p->right);
			break;
		}
		default:
		{
			break;
		}
		}
	}

	if (p->left->left != nullptr && p->right->right == nullptr)
	{
		switch (p->data)
		{
		case 1:
		{
			return f_eval(p->left) + p->right->data;
			break;
		}
		case 2:
		{
			return f_eval(p->left) - p->right->data;
			break;
		}
		case 3:
		{
			return f_eval(p->left) * p->right->data;
			break;
		}
		case 4:
		{
			return f_eval(p->left) / p->right->data;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	
	if (p->left->left != nullptr && p->right->right != nullptr)
	{
		switch (p->data)
		{
		case 1:
		{
			return f_eval(p->left) + f_eval(p->right);
			break;
		}
		case 2:
		{
			return f_eval(p->left) - f_eval(p->right);
			break;
		}
		case 3:
		{
			return f_eval(p->left) * f_eval(p->right);
			break;
		}
		case 4:
		{
			return f_eval(p->left) / f_eval(p->right);
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return 0;
}

void BTree::f_del0(BNode*& r)
{
	if (r == nullptr)
	{
		return;
	}
	if (r->data == 0)
	{
		f_del(r);  
		return;
	}
	f_del0(r->left);
	f_del0(r->right);
}

void BTree::f_delLeaves(BNode*& r)
{
	if (r == nullptr)
	{
		return;
	}
	if (r->left == nullptr && r->right == nullptr)
	{
		delete r;
		r = nullptr;
		return;
	}
	f_delLeaves(r->left);
	f_delLeaves(r->right);
}

void BTree::f_enlarge(BNode* r, int d)
{
	
	if (r->left == nullptr)
	{
		r->left = new BNode(d);
	}
	else
	{
		f_enlarge(r->left, d);
	}
	if (r->right == nullptr)
	{
		r->right = new BNode(d);
	}
	else
	{
		f_enlarge(r->right, d);
	}
	
}

void BTree::f_del1(BNode*& r)
{
	if (r == nullptr)
	{
		return;
	}
	BNode* p;
	if (r->left != nullptr && r->left->data == 1) 
	{
		f_del(r->left->left);
		p = r->left->right;
		delete r->left;
		r->left = p;
	}
	if (r->right != nullptr && r->right->data == 1)
	{
		f_del(r->right->left);
		p = r->right->right;
		delete r->right;
		r->right = p;
	}
	f_del1(r->left);
	f_del1(r->right);

}

int BTree::f_sum_alt(BNode* r, int s)
{
	if (r == nullptr)
	{
		return s;
	}
	if (r->left != nullptr && r->right != nullptr && r->left->data < 0 && r->right->data >= 0)
	{
		s += r->left->data + r->right->data;
	}
	return f_sum_alt(r->left, s) + f_sum_alt(r->right, s) - s;
}

BNode* BTree::f_find_rec(BNode* p, int d)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	if (p->data == d)
	{
		return p;
	}
	if (d > p->data)
	{
		return f_find_rec(p->right, d);
	}
	if (d < p->data)
	{
		return f_find_rec(p->left, d);
	}

}

BNode* BTree::f_find_cycle(BNode* p, int d)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	while (p != nullptr)
	{
		if (d == p->data)
		{
			return p;
		}
		if (d < p->data)
		{
			p = p->left;
		}
		else if (d > p->data)
		{
			p = p->right;
		}
	}
	return nullptr;
}

void BTree::f_insert_rec(BNode*& p, int d)
{
	if (p == nullptr)
	{
		p = new BNode(d);
		return;
	}
	if (p->data == d)
	{
		cout << "Ошибка: элемент " << d << " уже существует" << endl;
		return;
	}
	if (d > p->data)
	{
		if(p->right != nullptr)
		{
			f_insert_rec(p->right, d);
		}
		else
		{
			p->right = new BNode(d);
			return;
		}
	}
	if (d < p->data)
	{
		if (p->left != nullptr)
		{
			f_insert_rec(p->left, d);
		}
		else
		{
			p->left = new BNode(d);
			return;
		}
	}
	return;
}

void BTree::f_insert_cycle(BNode*& p, int d)
{
	if (p == nullptr)
	{
		p = new BNode(d);
		return;
	}
	BNode* t;
	t = p;
	while (t != nullptr)
	{
		if (d == t->data)
		{
			cout << "Ошибка: элемент "<< d << " уже существует" << endl;
			return;
		}
		if (d < t->data)
		{
			if (t->left != nullptr)
			{
				t = t->left;
			}
			else
			{
				t->left = new BNode(d);
				return;
			}
			
		}
		else if (d > t->data)
		{
			if (t->right != nullptr)
			{
				t = t->right;
			}
			else
			{
				t->right = new BNode(d);
				return;
			}
		}
	}
	return;
}
