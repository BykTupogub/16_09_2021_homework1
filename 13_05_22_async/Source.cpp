#include <iostream>
#include <future>
#include <omp.h>
#include<iomanip>
#include <vector>

using namespace std;

void line_pi(int n);

int block_size(int threads, int n);

long double calulate_pi(int a, int b, int n);

void MultiThread_pi(int threads, int n);

int Find(string what, string s, int a, int b);

int Find_thread(string what, string s, int threads, int first_index);

int MultiThreadFind(string what, string s, int threads);

int main()
{
	line_pi(10'000'000);
	MultiThread_pi(2, 10'000'000);

	///////////////////////////////////

	
	string s = "54321381114351684513545111135443164651354111461354984316811432168111432168432165435161118431684684684111"; // 6
	string what = "111";

	double t = omp_get_wtime();
	cout << Find(what, s, 0, s.size()) << endl;
	cout << setprecision(6) << "find line: " << omp_get_wtime() - t << endl;
	t = omp_get_wtime();
	cout << MultiThreadFind(what, s, 2) << endl;
	cout << setprecision(6) << "find MultiThread: " << omp_get_wtime() - t << endl;


	return EXIT_SUCCESS;
}
void line_pi(int n)
{
	long double pi = 0;
	double t = omp_get_wtime();
	for (int i = 0; i < n; ++i)
	{
		pi += (1.0 / (1.0 + ((2.0 * i - 1) / (2.0 * n)) * ((2.0 * i - 1) / (2.0 * n))));
	}
	pi = pi * 4 / n;
	cout << "Time line: " << omp_get_wtime() - t << endl;
	cout << setprecision(15) << "pi = " << pi << endl;
}

int block_size(int threads, int n)
{
	return n / threads + (n % threads ? 1 : 0);
}

long double calulate_pi(int a, int b, int n)
{
	long double pi = 0;
	for (int i = a; i < b; ++i)
	{
		pi += (1.0 / (1.0 + ((2.0 * i - 1) / (2.0 * n)) * ((2.0 * i - 1) / (2.0 * n))));
	}

	return pi;
}

void MultiThread_pi(int threads, int n)
{
	double t = omp_get_wtime();
	long double pi = 0;
	vector<future <long double>> fut(threads);
	int bl_size = block_size(threads, n);
	int first_index = 0;
	int i = 0;
	while (first_index < n)
	{
		fut[i] = async(calulate_pi, first_index, first_index + bl_size, n);

		first_index += bl_size;
		i++;
	}

	for (int j = 0; j < i; ++j)
	{
		pi += fut[j].get();
	}


	pi = pi * 4 / n;
	cout << "Time MultiThread_pi: " << omp_get_wtime() - t << endl;
	cout << setprecision(15) << "pi = " << pi << endl;
	
}

int Find(string what, string s, int a, int b)
{
	int n = 0;
	for (int i = a; i < b; ++i)
	{
		
		if (what[0] == s[i])
		{
			++n;
			
			for (int j = 1; j < what.size() && i + j < b; ++j)
			{
				if (what[j] != s[j + i])
				{
					--n;
					i -= what.size();
					break;
				}
			}
			i += what.size();
		}
	}
	return n;
}

int Find_thread(string what, string s, int threads, int a)
{
	int b = a + block_size(threads, s.size());
	if (a != 0)
	{
		b += what.size() - 1;
	}
	int n = 0;
	for (int i = a; i < b; ++i)
	{

		if (what[0] == s[i])
		{
			++n;
			for (int j = 1; j < what.size() && i + j < b; ++j)
			{
				if (what[j] != s[j + i])
				{
					--n;
					i -= what.size();
					break;
				}
			}
			i += what.size();
		}
	}
	return n;
}

int MultiThreadFind(string what, string s, int threads)
{

	int n = 0;
	vector<future <int>> fut(threads);
	int bl_size = block_size(threads, s.size());
	int first_index = 0;
	int i = 1;
	fut[0] = async(Find_thread, what, s, threads, first_index);
	first_index += bl_size;
	while (first_index < s.size())
	{
		fut[i] = async(Find_thread, what, s, threads, first_index - what.size() + 1);

		first_index += bl_size;
		++i;
	}

	for (int j = 0; j < i; ++j)
	{
		n += fut[j].get();
	}
	return n;
}
