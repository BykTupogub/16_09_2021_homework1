#include<iostream>
#include<fstream>
#include"Mosaic.h"

using namespace std;

int main()
{
	ifstream fin("input.txt");
	int n;
	int m;
	fin >> m;
	fin >> n;
	cout << n << " " << m << endl;
	int** arr;
	arr = new int* [m];   
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			fin >> arr[i][j];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	Mosaic mosaic(n, m, arr);

	mosaic.print();
	cout << endl << endl;

	mosaic.solve();
	
	mosaic.print_free();
	cout << endl << endl;
	mosaic.print_color();
	cout << endl << endl;
	
	

	delete[] arr;
	return EXIT_SUCCESS;
}
