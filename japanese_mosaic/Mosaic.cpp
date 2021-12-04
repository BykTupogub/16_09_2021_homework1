#include<iostream>
#include "Mosaic.h"

using namespace std;

Mosaic::Mosaic(int n, int m, int** arr)
{
	N = n;
	M = m;
	mos = new MNode* [M];
	for (int i = 0; i < M; i++) {
		mos[i] = new MNode[N];
		for (int j = 0; j < N; ++j)
		{
			mos[i][j].data = arr[i][j];
		}
	}
	
}

Mosaic::~Mosaic()
{
	delete[] mos;
}

void Mosaic::print()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mos[i][j].data != -1)
			{
				cout << mos[i][j].data << " ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;

	}
}

void Mosaic::print_free()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mos[i][j].data != -1)
			{
				cout << mos[i][j].free << " ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;

	}
}

void Mosaic::print_color()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mos[i][j].color != 2)
			{
				cout << mos[i][j].color << " ";
			}
			else
			{
				cout << "  ";
			}
			
		}
		cout << endl;

	}
}

bool Mosaic::index_correct(int i, int j)
{
	if (i < M && i >= 0 && j < N && j >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Mosaic::coating(int i, int j, int c)
{
	if (index_correct(i, j) && mos[i][j].color == 2)
	{
		mos[i][j].color = c;
	}
	if (index_correct(i + 1, j) && mos[i + 1][j].color == 2)
	{
		mos[i + 1][j].color = c;
	}
	if (index_correct(i - 1, j) && mos[i - 1][j].color == 2)
	{
		mos[i - 1][j].color = c;
	}
	if (index_correct(i, j + 1) && mos[i][j + 1].color == 2)
	{
		mos[i][j + 1].color = c;
	}
	if (index_correct(i + 1, j + 1) && mos[i + 1][j + 1].color == 2)
	{
		mos[i + 1][j + 1].color = c;
	}
	if (index_correct(i - 1, j + 1) && mos[i - 1][j + 1].color == 2)
	{
		mos[i - 1][j + 1].color = c;
	}
	if (index_correct(i, j - 1) && mos[i][j - 1].color == 2)
	{
		mos[i][j - 1].color = c;
	}
	if (index_correct(i + 1, j - 1) && mos[i + 1][j - 1].color == 2)
	{
		mos[i + 1][j - 1].color = c;
	}
	if (index_correct(i - 1, j - 1) && mos[i - 1][j - 1].color == 2)
	{
		mos[i - 1][j - 1].color = c;
	}
	
}

int Mosaic::number_of_whites(int i, int j)
{
	int x = 0;
	if (mos[i][j].color != 0)
	{
		++x;
	}
	if (index_correct(i + 1, j) && mos[i + 1][j].color == 0)
	{
		++x;
	}
	if (index_correct(i - 1, j) && mos[i - 1][j].color == 0)
	{
		++x;
	}
	if (index_correct(i, j + 1) && mos[i][j + 1].color == 0)
	{
		++x;
	}
	if (index_correct(i + 1, j + 1) && mos[i + 1][j + 1].color == 0)
	{
		++x;
	}
	if (index_correct(i - 1, j + 1) && mos[i - 1][j + 1].color == 0)
	{
		++x;
	}
	if (index_correct(i, j - 1) && mos[i][j - 1].color == 0)
	{
		++x;
	}
	if (index_correct(i + 1, j - 1) && mos[i + 1][j - 1].color == 0)
	{
		++x;
	}
	if (index_correct(i - 1, j - 1) && mos[i - 1][j - 1].color == 0)
	{
		++x;
	}
	return x;
}

int Mosaic::number_of_black(int i, int j)
{
	int x = 0;
	if (mos[i][j].color == 1)
	{
		++x;
	}
	if (index_correct(i + 1, j) && mos[i + 1][j].color == 1)
	{
		++x;
	}
	if (index_correct(i - 1, j) && mos[i - 1][j].color == 1)
	{
		++x;
	}
	if (index_correct(i, j + 1) && mos[i][j + 1].color == 1)
	{
		++x;
	}
	if (index_correct(i + 1, j + 1) && mos[i + 1][j + 1].color == 1)
	{
		++x;
	}
	if (index_correct(i - 1, j + 1) && mos[i - 1][j + 1].color == 1)
	{
		++x;
	}
	if (index_correct(i, j - 1) && mos[i][j - 1].color == 1)
	{
		++x;
	}
	if (index_correct(i + 1, j - 1) && mos[i + 1][j - 1].color == 1)
	{
		++x;
	}
	if (index_correct(i - 1, j - 1) && mos[i - 1][j - 1].color == 1)
	{
		++x;
	}
	return x;
}

int Mosaic::number_of_empty(int i, int j)
{
	int x = 0;
	if (mos[i][j].color == 2)
	{
		++x;
	}
	if (index_correct(i + 1, j) && mos[i + 1][j].color == 2)
	{
		++x;
	}
	if (index_correct(i - 1, j) && mos[i - 1][j].color == 2)
	{
		++x;
	}
	if (index_correct(i, j + 1) && mos[i][j + 1].color == 2)
	{
		++x;
	}
	if (index_correct(i + 1, j + 1) && mos[i + 1][j + 1].color == 2)
	{
		++x;
	}
	if (index_correct(i - 1, j + 1) && mos[i - 1][j + 1].color == 2)
	{
		++x;
	}
	if (index_correct(i, j - 1) && mos[i][j - 1].color == 2)
	{
		++x;
	}
	if (index_correct(i + 1, j - 1) && mos[i + 1][j - 1].color == 2)
	{
		++x;
	}
	if (index_correct(i - 1, j - 1) && mos[i - 1][j - 1].color == 2)
	{
		++x;
	}
	return x;
}

void Mosaic::solv_free(int i, int j)
{
	if (number_of_black(i, j) == mos[i][j].data)
	{
		mos[i][j].free = 9;
	}
	else
	{
		mos[i][j].free = number_of_empty(i, j) - mos[i][j].data + number_of_black(i, j);
	}
	

}

void Mosaic::horizontal3(int i, int j, int c)
{
	if (index_correct(i - 1, j))
	{
		mos[i - 1][j].color = c;
	}
	if (index_correct(i - 1, j + 1))
	{
		mos[i - 1][j + 1].color = c;
	}
	if (index_correct(i - 1, j - 1))
	{
		mos[i - 1][j - 1].color = c;
	}
	
	if (c == 1)
	{
		c = 0;
	}
	else
	{
		c = 1;
	}

	if (index_correct(i + 2, j))
	{
		mos[i + 2][j].color = c;
	}
	if (index_correct(i + 2, j + 1))
	{
		mos[i + 2][j + 1].color = c;
	}
	if (index_correct(i + 2, j - 1))
	{
		mos[i + 2][j - 1].color = c;
	}
}

void Mosaic::vertical3(int i, int j, int c)
{
	if (index_correct(i, j - 1))
	{
		mos[i][j - 1].color = c;
	}
	if (index_correct(i + 1, j - 1))
	{
		mos[i + 1][j - 1].color = c;
	}
	if (index_correct(i - 1, j - 1))
	{
		mos[i - 1][j - 1].color = c;
	}

	if (c == 1)
	{
		c = 0;
	}
	else
	{
		c = 1;
	}

	if (index_correct(i, j + 2))
	{
		mos[i][j + 2].color = c;
	}
	if (index_correct(i + 1, j + 2))
	{
		mos[i + 1][j + 2].color = c;
	}
	if (index_correct(i - 1, j + 2))
	{
		mos[i - 1][j + 2].color = c;
	}
}

bool Mosaic::horizontal2(int i, int j, int c)
{
	int k = 0;
	if ((!index_correct(i - 1, j - 1) || mos[i - 1][j - 1].color == 1) &&
		(!index_correct(i, j - 1) || mos[i][j - 1].color == 1) &&
		(!index_correct(i + 1, j - 1) || mos[i + 1][j - 1].color == 1) &&
		(!index_correct(i + 2, j - 1) || mos[i + 2][j - 1].color == 1)
		)
	{ 
		k = 1;
	}
	if ((!index_correct(i - 1, j + 1) || mos[i - 1][j + 1].color == 1) &&
		(!index_correct(i, j + 1) || mos[i][j + 1].color == 1) &&
		(!index_correct(i + 1, j + 1) || mos[i + 1][j + 1].color == 1) &&
		(!index_correct(i + 2, j + 1) || mos[i + 2][j + 1].color == 1)
		)
	{
		k = -1;
	}
	if (k != 0)
	{
		if (index_correct(i - 1, j))
		{
			mos[i - 1][j].color = c;
		}
		if (index_correct(i - 1, j + k))
		{
			mos[i - 1][j + k].color = c;
		}
		if (c == 1)
		{
			c = 0;
		}
		else
		{
			c = 1;
		}
		if (index_correct(i + 2, j))
		{
			mos[i + 2][j].color = c;
		}
		if (index_correct(i + 2, j + k))
		{
			mos[i + 2][j + k].color = c;
		}
		
		return true;
	}
	return false;
}

bool Mosaic::vertical2(int i, int j, int c)
{
	int k = 0;
	if ((!index_correct(i - 1, j - 1) || mos[i - 1][j - 1].color == 1) &&
		(!index_correct(i - 1, j) || mos[i - 1][j].color == 1) &&
		(!index_correct(i - 1, j + 1) || mos[i - 1][j + 1].color == 1) &&
		(!index_correct(i - 1, j + 2) || mos[i - 1][j + 2].color == 1)
		)
	{
		k = 1;
	}
	if ((!index_correct(i + 1, j - 1) || mos[i + 1][j - 1].color == 1) &&
		(!index_correct(i + 1, j) || mos[i + 1][j].color == 1) &&
		(!index_correct(i + 1, j + 1) || mos[i + 1][j + 1].color == 1) &&
		(!index_correct(i + 1, j + 2) || mos[i + 1][j + 2].color == 1)
		)
	{
		k = -1;
	}
	if (k != 0)
	{
		if (index_correct(i, j - 1))
		{
			mos[i][j - 1].color = c;
		}
		if (index_correct(i + k, j - 1))
		{
			mos[i + k][j - 1].color = c;
		}
		if (c == 1)
		{
			c = 0;
		}
		else
		{
			c = 1;
		}
		if (index_correct(i, j + 2))
		{
			mos[i][j + 2].color = c;
		}
		if (index_correct(i + k, j + 2))
		{
			mos[i + k][j + 2].color = c;
		}

		return true;
	}
	return false;
}

bool Mosaic::first_case(int i, int j)
{
	if (index_correct(i + 1, j) && mos[i][j].data - mos[i + 1][j].data == 3 && mos[i + 1][j].data != -1)
	{
		horizontal3(i, j, 1);
		return true;
	}
	if (index_correct(i + 1, j) && mos[i][j].data - mos[i + 1][j].data == -3 && mos[i + 1][j].data != -1)
	{
		horizontal3(i, j, 0);
		return true;
	}
	if (index_correct(i, j + 1) && mos[i][j].data - mos[i][j + 1].data == 3 && mos[i][j + 1].data != -1)
	{
		vertical3(i, j, 1);
		return true;
	}
	if (index_correct(i, j + 1) && mos[i][j].data - mos[i][j + 1].data == -3 && mos[i][j + 1].data != -1)
	{
		vertical3(i, j, 0);
		return true;
	}
	return false;
}

bool Mosaic::second_case(int i, int j)
{
	
	if (index_correct(i + 1, j) && mos[i][j].data - mos[i + 1][j].data == 2 && mos[i + 1][j].data != -1)
	{
		return horizontal2(i, j, 1);
	}
	if (index_correct(i + 1, j) && mos[i][j].data - mos[i + 1][j].data == -2 && mos[i + 1][j].data != -1)
	{
		return horizontal2(i, j, 0);
	}
	if (index_correct(i, j + 1) && mos[i][j].data - mos[i][j + 1].data == 2 && mos[i][j + 1].data != -1)
	{
		return vertical2(i, j, 1);
	}
	if (index_correct(i, j + 1) && mos[i][j].data - mos[i][j + 1].data == -2 && mos[i + 1][j + 1].data != -1)
	{
		return vertical2(i, j, 0);
		
	}
	return false;
}

bool Mosaic::color1()
{
	bool r = false;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mos[i][j].data != -1 && !mos[i][j].all)
			{
				solv_free(i, j);
				if (mos[i][j].free == 0)
				{
					r = true;
					coating(i, j, 1);
					mos[i][j].all = true;
				}
				if (mos[i][j].free == 9)
				{
					r = true;
					coating(i, j, 0);
					mos[i][j].all = true;
				}
			}
		}
	}
	return r;
}

bool Mosaic::color2()
{
	bool r = false;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mos[i][j].data != -1 && !mos[i][j].all)
			{
				r = first_case(i, j) || second_case(i, j);
			}
		}
	}
	return r;
}

bool Mosaic::is_solved()
{
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mos[i][j].color == 2)
			{
				return false;
			}
		}
	}
	return true;
}

void Mosaic::solve()
{
	while (!is_solved())
	{
		while (color1() || color2());
	}

	cout << endl;
}

