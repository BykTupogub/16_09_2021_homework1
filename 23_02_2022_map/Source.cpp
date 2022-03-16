#include<iostream>
#include<map>
#include<set>


using namespace std;

template<class T1, class T2>
void print(map<T1, T2> m);

void number_of_occurrences();

map<int, int> read_int_int();

void result_int_int();

template<class T1, class T2, class T3>
map<T1, T3> composition(map<T1, T2> map1, map<T2, T3> map2);



int main()
{
	setlocale(LC_ALL, "Russian");

	//number_of_occurrences();

	/*
	map<int, int> m;
	m = read_int_int();
	print(m);
	*/

	//result_int_int();
	
	/*
	map<int, int> m1;
	m1 = read_int_int();
	map<int, int> m2;
	m2 = read_int_int();
	map<int, int> m3;
	m3 = sum(m1, m2);
	cout << "sum =" << endl;
	print(m3);
	*/
	map<int, int> map1;
	map1 = read_int_int();
	map<int, int> map2;
	map2 = read_int_int();
	map<int, int> map3;
	map3 = composition(map1, map2);
	cout << "composition =" << endl;
	print(map3);


	return EXIT_SUCCESS;
}

template<class T1, class T2>
void print(map<T1, T2> m)
{
	for (auto x : m)
	{
		cout << x.first << " -> " << x.second << endl;
	}
}

template<class T1, class T2>
map<T1, T2> sum(map<T1, T2> map1, map<T1, T2> map2)
{
	map<T1, T2> m;
	for (auto x : map1)
	{
		m[x.first] = map1[x.first] + map2[x.first];
	}
	return m;
}

template<class T1, class T2, class T3>
map<T1, T3> composition(map<T1, T2> map1, map<T2, T3> map2)
{
	map<T1, T3> m;
	for (auto x : map1)
	{
		m[x.first] = map2[x.second];
	}
	return m;
}

void number_of_occurrences()
{
	map<int, int> m;
	int x;
	while (cin >> x)
	{
		if (m.count(x))
		{
			++m[x];
		}
		else
		{
			m[x] = 1;
		}
	}
	print(m);
}

map<int, int> read_int_int()
{
	map<int, int> m;
	int a = 0;
	int b = 0;
	int n = 0;
	cout << "введите число пар" << endl;
	cin >> n;
	cout << "введите пары" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		m[a] = b;
	}

	return m;
}

void result_int_int()
{
	map<int, int> m;
	m = read_int_int();
	cout << "введите набор" << endl;
	int x = 0;
	while (cin >> x)
	{
		if (m.count(x))
		{
			cout  << m[x] << endl;
		}
		else
		{
			cout  << x << endl;
		}
	}
}
