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
	cout << "-----------------------------" << endl;
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
	



	return EXIT_SUCCESS;
}