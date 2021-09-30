#include <omp.h>
#include <vector>
#include <iostream>
#include "List.h"

using namespace std;

bool f(int a);

int main()
{
	List l;
	l.add_first(5);
	l.add_first(4);
	l.add_first(3);
	l.add_first(2);
	l.add_first(1);
	l.print();
	
	List l2(l);
	l2.print();
	l.del();
	l.print();
	l2.print();
	List l3 = l2;
	l3.print();
	l2.print();
	
	List a;
	for (int i = 0; i < 100; ++i)
	{
		a.add_first(0);
	}
	
	double t1 = omp_get_wtime();
	for (int i = 0; i < 20000000; ++i)
	{
		a.get_ptr(50);
	}
	double t2 = omp_get_wtime();
	double time1 = t2 - t1;
	cout << "Time1: " << t2 - t1 << endl;
	
	vector<int> b;
	for (int i = 0; i < 100; ++i)
	{
		b.push_back(0);
	}

	t1 = omp_get_wtime();
	for (int i = 0; i < 20000000; ++i)
	{
		b[50];
	}
	t2 = omp_get_wtime();
	double time2 = t2 - t1;
	cout << "Time2: " << t2 - t1 << endl;
	cout << "Time1/Time2 = " << time1 / time2 << endl;

	
	return EXIT_SUCCESS;
}

bool f(int a)
{
	return a % 2 == 0 ? true : false;
}


