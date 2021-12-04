#pragma once

struct MNode
{
	int data;
	int free;
	int color;
	bool all;

	MNode(int d = -1, int f = 9, int c = 2, bool a = false) :
		data(d), free(f), color(c), all(a){}
};

struct Mosaic
{
	int N;
	int M;

	MNode** mos;

	Mosaic(int n, int m, int** arr);
	~Mosaic();

	void print();

	void print_free();

	void print_color();

	bool index_correct(int i, int j);

	void coating(int i, int j, int c);

	int number_of_whites(int i, int j);

	int number_of_black(int i, int j);

	int number_of_empty(int i, int j);

	void solv_free(int i, int j);

	void horizontal3(int i, int j, int c);

	void vertical3(int i, int j, int c);

	bool horizontal2(int i, int j, int c);

	bool vertical2(int i, int j, int c);

	bool first_case(int i, int j);

	bool second_case(int i, int j);

	bool color1();

	bool color2();

	bool is_solved();

	void solve();

};