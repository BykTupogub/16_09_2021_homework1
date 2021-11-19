#include<iostream>
#include "Btree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	BNode* p10 = new BNode(5);
	///////////
	BNode* p9 = new BNode(4);
	BNode* p8 = new BNode(7);
	BNode* p7 = new BNode(13);
	BNode* p6 = new BNode(1, nullptr, p10);
	BNode* p5 = new BNode(6, p9, p8);
	BNode* p4 = new BNode(14, p7);
	BNode* p3 = new BNode(3, p6, p5);
	BNode* p2 = new BNode(10, nullptr, p4);
	BNode* p1 = new BNode(8, p3, p2);
	BTree tree(p1);
	tree.print();
	cout << "Самый левый узел: " << tree.leftmost()->data << endl;
	cout << "Удалим самый левый узел" << endl;
	tree.delleftmost();
	tree.print();
	cout << "Самый левый лист: " << tree.leftleaf()->data << endl;
	cout << "Удалим самый левый лист" << endl;
	tree.delleftleaf();
	tree.print();
	cout << "Добавим левого сына 12 у самого левого узла" << endl;
	tree.putleft(12);
	tree.print();
	cout << "Второй лист слева: " << tree.second_from_left_leaf()->data << endl;
	
	///////////////////////////////  Обход дерева
	cout << "---------------------------" << endl;
	cout << "ОБХОД ДЕРЕВА" << endl;
	cout << "scale:" << endl;
	tree.scale();
	tree.print();
	cout << "sum: " << tree.sum() << endl;
	cout << "Дщбавим несколько узлов с отрицательными значениями" << endl;
	tree.putleft(-1);
	tree.putleft(-1);
	tree.putleft(-1);
	tree.print();
	cout << "count_neg: " << tree.count_neg() << endl;
	cout << "height: " << tree.height() << endl;
	tree.delleftleaf();
	tree.delleftleaf();
	tree.delleftleaf();
	tree.print();
	cout << "reflect: " << endl;
	tree.reflect();
	tree.print();
	cout << "mult: " << tree.mult() << " (18 * 24)" << endl;
	cout << endl;
	cout << "Дерево представляющее выражение ((3*6)/(1+1))+(4-3) = 10 :" << endl;
	
	BNode* q11 = new BNode(3);
	BNode* q10 = new BNode(6);
	BNode* q9 = new BNode(1);
	BNode* q8 = new BNode(1);
	BNode* q7 = new BNode(3, q11, q10); // *
	BNode* q6 = new BNode(1, q9, q8);
	BNode* q5 = new BNode(4);
	BNode* q4 = new BNode(3);
	BNode* q3 = new BNode(4, q7, q6); // /
	BNode* q2 = new BNode(2, q5, q4); // -
	BNode* q1 = new BNode(1, q3, q2); // +
	BTree tree2(q1);
	tree2.print();
	cout << "eval: " << tree2.eval() << endl;


	return EXIT_SUCCESS;
}