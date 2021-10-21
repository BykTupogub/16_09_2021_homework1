#include<iostream>
#include<vector>

using namespace std;

template <typename T>
void print(vector<T> v);

template <typename T>
void enlarge(vector<T>& v);

template <typename T>
void del(vector<T>& v);

template <typename T>
vector<T> concat(vector<T> a, vector<T> b);

template <typename T>
vector<T> repeat(int n, vector<T> a);


int main()
{
	vector<int> v{2, 4, 6, 8, 10};
		
	print(v);
	enlarge(v);
	print(v);
	del(v);
	print(v);

	cout << endl;
	vector<int> v2{1, 2, 3, 4, 5, 6};
	int* arr = new int[v2.size()];
	copy(v2.begin(), v2.end(), arr);
	for (int i = 0; i < v2.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int> v3 = concat(v, v2);
	print(v3);

	vector<int> v4 = repeat(5, v);
	print(v4);

	return EXIT_SUCCESS;
}

template<typename T>
void print(vector<T> v)
{
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

template<typename T>
void enlarge(vector<T>& v)
{
	T a;
	for (auto i = v.begin(); i != --v.end(); ++i)
	{
		a = *i;
		++i;
		i = v.insert(i, (*i + a) / 2);
	}

}

template<typename T>
void del(vector<T>& v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		i = v.erase(i);
		if (i == v.end())
		{
			return;
		}
		
	}
}

template<typename T>
vector<T> concat(vector<T> a, vector<T> b)
{
	vector<T> v;
	v.resize(a.size() + b.size());
	copy(a.begin(), a.end(), v.begin());
	copy(b.begin(), b.end(), v.begin()+=a.size());

	return v;
}

template<typename T>
vector<T> repeat(int n, vector<T> a)
{
	vector<T> v;
	v.resize(n * a.size());
	for (int i = 0; i < n; ++i)
	{
		copy(a.begin(), a.end(), v.begin()+=(a.size()*i));
	}
	return v;
}

