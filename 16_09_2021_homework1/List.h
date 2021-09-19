#pragma once


struct Node
{
	int data;
	Node* next;
	Node(int d = 0, Node* n = nullptr) : data(d), next(n) {}

};


struct List
{

private:

	Node* head;
	
	
public:
	
	List() : head(nullptr) {}

	List(const List& l);

	~List();

private:

	bool indexValid(int n);

public:

	int length();

	void add_first(int d);

	void print();

	Node* last();

	Node* prelast();

	Node* get_ptr(int n);

	void add_after_first(int d);

	void add_last(int d);

	void del_last();

	bool insertp(int n, int p);

	bool delp(int n);

	void reverse();

	void remove_if(bool (*f)(int));

	void del();

	List& operator= (const List& l);

};


