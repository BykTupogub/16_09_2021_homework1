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

	cout << "Рассмотрим дерево:" << endl;

	BNode* s11 = new BNode(0);
	BNode* s10 = new BNode(6);
	BNode* s9 = new BNode(1);
	BNode* s8 = new BNode(1);
	BNode* s7 = new BNode(5, s11, s10); 
	BNode* s6 = new BNode(0, s9, s8);
	BNode* s5 = new BNode(4);
	BNode* s4 = new BNode(3);
	BNode* s3 = new BNode(1, s7, s6); 
	BNode* s2 = new BNode(5, s5, s4);
	BNode* s1 = new BNode(3, s3, s2); 
	BTree tree3(s1);
	tree3.print();
	cout << "Удалим все узлы и их поддеревья содержащие 0" << endl;
	tree3.del0();
	tree3.print();
	cout << "Удалим все листья" << endl;
	tree3.delLeaves();
	tree3.print();
	cout << "Заменим все указатели нулями" << endl;
	tree3.enlarge(0);
	tree3.print();
	cout << "Удалим узлы с единицей и их левые поддеревья" << endl;
	tree3.del1();
	tree3.print();
	cout << "Рассмотрим дерево:" << endl;
	BNode* k11 = new BNode(-2);
	BNode* k10 = new BNode(6);
	BNode* k9 = new BNode(-1);
	BNode* k8 = new BNode(2);
	BNode* k7 = new BNode(-3, k11, k10);
	BNode* k6 = new BNode(0, k9, k8);
	BNode* k5 = new BNode(4);
	BNode* k4 = new BNode(3);
	BNode* k3 = new BNode(1, k7, k6);
	BNode* k2 = new BNode(5, k5, k4);
	BNode* k1 = new BNode(3, k3, k2);
	BTree tree4(k1);
	tree4.print();
	cout << "sum_alt: " << tree4.sum_alt() << endl;

	cout << "Построим дерево двоичного поиска:" << endl;
	BNode* t15 = new BNode(15);
	BNode* t14 = new BNode(49);
	BNode* t13 = new BNode(76);
	BNode* t12 = new BNode(93);
	BNode* t11 = new BNode(101);
	BNode* t10 = new BNode(110);
	BNode* t9 = new BNode(121);
	BNode* t8 = new BNode(175);
	BNode* t7 = new BNode(37, t15, t14);
	BNode* t6 = new BNode(85, t13, t12);
	BNode* t5 = new BNode(107, t11, t10);
	BNode* t4 = new BNode(150, t9, t8);
	BNode* t3 = new BNode(70, t7, t6);
	BNode* t2 = new BNode(113, t5, t4);
	BNode* t1 = new BNode(100, t3, t2);
	BTree tree5(t1);
	tree5.print();

	cout << "найдём элемент 101 с помощью рекурсивной функции: " << tree5.find_rec(101)->data << " - " << tree5.find_rec(101) << endl;
	cout << "найдём элемент 101 с помощью функции с циклом: " << tree5.find_cycle(101)->data << " - " << tree5.find_cycle(101) << endl;
	cout << "Вставим элемент 48 и элемент 72 с помощью рекурсивной функции и функции с циклом" << endl;
	tree5.insert_rec(48);
	tree5.insert_cycle(71);
	tree5.print();

	return EXIT_SUCCESS;
}