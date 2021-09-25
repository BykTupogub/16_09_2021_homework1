#pragma once

struct DNode
{
	int data;
	DNode* next;
	DNode* prev;
	DNode(int d = 0, DNode* n = nullptr, DNode* p = nullptr) :
		data(d), next(n), prev(p) {}
};

struct DList
{
private:
	DNode* head;
	DNode* tail;
public:

	DList() { head = nullptr; tail = nullptr;}

private:
	
	bool indexValid(int n);

public:

	int length();

	void add_first(int d);

	void add_last(int d);

	DNode* last();

	DNode* prelast();

	void print();

	/////
	void reprint();

	void add_after_first(int d);

	void del_last();

	void del_second();

	void del_first();

	bool insertp(int n, int p);

	bool delp(int n);

	void reverse();

	void remove_if(bool(*f)(int));


};