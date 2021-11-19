#pragma once

struct BNode
{
	int data;
	BNode* left;
	BNode* right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {}
};


struct BTree
{
public:

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

	int count();

	void scale();

	int sum();

	int count_neg();

	int height();

	void reflect();

	int mult();

	int eval();

	template<class T>
	BNode* find(T d);

private:

	BNode* root;

	static void f_print(BNode* r, int indent = 0);

	static BNode* f_preleftmost(BNode* r, BNode* p, int a, int& m);

	static BNode* f_preleftleaf(BNode* r, BNode* p, int a, int& m);

	static BNode* f_second_from_left_leaf(BNode* r, BNode* p, BNode* l, int a, int& m);

	static int f_count(BNode* p);

	static void f_scale(BNode* p);

	static int f_sum(BNode* p);

	static int f_count_neg(BNode* p);

	static int f_height(BNode* p, int h, int& m);

	static void f_reflect(BNode* p);

	static int f_mult(BNode* p);

	static int f_eval(BNode* p);

	template<class T>
	static BNode* f_find(BNode* p, T d);
};

/////////////////////////
template<class T>
inline BNode* BTree::find(T d)
{
	return f_find(root, d);
}

template<class T>
inline BNode* BTree::f_find(BNode* p, T d)
{

	
	return nullptr;
	
}
