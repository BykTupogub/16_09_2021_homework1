#include <iostream>
#include "DList.h"
//#define print reprint

using namespace std;

bool f(int a);

int main()
{

	DList l;
	l.add_first(4);
	l.add_first(1);
	l.add_after_first(3);
	l.add_after_first(2);
	l.add_last(5);
	l.add_last(6);
	l.print();
	/*
	cout << l.length() << endl;

	l.del_last();
	l.print();
	cout << l.length() << endl;

	l.del_second();
	l.print();
	cout << l.length() << endl;
	l.add_after_first(2);
	l.print();
	cout << l.length() << endl;

	DList ll;
	ll.add_first(4);
	ll.add_first(1);
	ll.print();
	ll.del_second();
	ll.print();
	ll.del_last();
	ll.print();

	l.insertp(3, 99);
	l.print();
	l.delp(3);
	l.print();
	l.remove_if(f);
	l.print();
	l.reverse();
	l.print();
	l.del_first();
	l.print();
	*/

	DList ll;
	ll = l;
	ll.print();
	ll.del();
	ll.print();



	return EXIT_SUCCESS;
}

bool f(int a)
{
	return a % 2 == 0 ? true : false;
}
