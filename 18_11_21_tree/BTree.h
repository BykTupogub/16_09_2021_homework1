#pragma once

struct BNode
{
	int data;
	BNode* left;
	BNode* right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {}
};

void f_print(BNode* r, int indent = 0);


struct BTree
{
	BNode* root;
	BTree(BNode* p) :
		root(p) {}

	void print();

	BNode* leftmost();

	BNode* preleftmost();

	void delleftmost();

	void putleft(int d);

	BNode* leftleaf();

	BNode* preleftleaf();

	void delleftleaf();

	BNode* second_from_left_leaf();

};

BNode* f_preleftmost(BNode* r, BNode* p, int a, int& m);

BNode* f_leftleaf(BNode* r, BNode* p, int a, int& m);

BNode* f_preleftleaf(BNode* r, BNode* p, int a, int& m);

BNode* f_second_from_left_leaf(BNode* r, BNode* p, BNode* l, int a, int& m);