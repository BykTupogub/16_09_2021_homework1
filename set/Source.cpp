#include<iostream>
#include"set"

using namespace std;

void print(set <int> s)
{
	for (auto x : s)
		cout << x << endl;
}

template<class T>
set<T> unite(set<T> v, set<T> u);

int main()
{
	set<int> s;
	int x = 0;
	

	while (cin >> x)
	{
		s.insert(x);
	}
	print(s);
	/////////////////////
	
	set<int>ss;
	cin.clear();
	s.clear();
	while (cin >> x)
	{
		if (ss.count(x))
		{
			s.insert(x);
		}
		ss.insert(x);
		
	}
	print(s);

	//////////////////////////
	/*
	cin.clear();
	s.clear();
	ss.clear();
	set<int>sss;
	while (cin >> x)
	{
		if (ss.count(x))
		{
			ss.erase(x);
			sss.insert(x);
		}
		if (s.count(x) && !sss.count(x))
		{
			ss.insert(x);
		}
		s.insert(x);
	}
	print(ss);
	*/

	cin.clear();
	s.clear();
	ss.clear();
	set<int>sss;
	while (cin >> x)
	{
		if (ss.count(x))
		{
			sss.insert(x);
		}
		if (s.count(x))
		{
			ss.insert(x);
		}
		s.insert(x);
	}
	for (auto i : ss)
	{
		if (!sss.count(i))
		{
			cout << i << endl;
		}
	}

	//////////////////////

	set<int>u;
	u.insert(1);
	u.insert(2);
	u.insert(3);
	set<int>v;
	v.insert(3);
	v.insert(4);
	v.insert(5);
	set<int> w = unite(u, v);
	//print(w);
	return EXIT_SUCCESS;
}

template<class T>
set<T> unite(set<T> v, set<T> u)
{
	set<T> w;
	typename set<T>::iterator i;
	for (i = u.begin(); i != u.end(); ++i)
	{
		w.insert(*i);
	}
	for (i = v.begin(); i != v.end(); ++i)
	{
		w.insert(*i);
	}
	return w;
}
