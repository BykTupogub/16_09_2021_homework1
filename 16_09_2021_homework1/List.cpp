#include<iostream>
#include "List.h"


Node* copy(Node* x)
{
	Node* y = nullptr;
	if (x != nullptr)
	{
		y = new Node(x->data, copy(x->next));
	}
	return y;
}


List::List(const List& l)
{
	head = copy(l.head); 
}

List::~List()
{
	del();
}

bool List::indexValid(int n)
{
	return n >= 0 && n < length();
}

int List::length()
{
	int i = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++i;
	}
	return i;
}

void List::add_first(int d)
{
	Node* tmp;
	tmp = new Node(d, head);
	head = tmp;
}

void List::print()
{
	if (head == nullptr)
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		Node* p = head;
		while (p != nullptr)
		{
			std::cout << p->data << "\t";
			p = p->next;
		}
		std::cout << std::endl;
	}
	
}

Node* List::last()
{
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	return tmp;
}

Node* List::prelast()
{
	Node* tmp = head;
	while (tmp->next->next != nullptr)
	{
		tmp = tmp->next;
	}
	return tmp;
}

Node* List::get_ptr(int n)
{
	Node* tmp = head;
	if (n > length())
	{
		return nullptr;
	}
	for (int i = 0; i < n; ++i)
	{
		tmp = tmp->next;
	}
	return tmp;
}

void List::add_after_first(int d)
{
	Node* tmp;
	tmp = new Node(d, head->next);
	head->next = tmp;
}

void List::add_last(int d)
{
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node(d, nullptr);
}

void List::del_last()
{
	Node* tmp = head;
	while(tmp->next->next != nullptr)
	{
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = nullptr;
}

bool List::insertp(int n, int p)
{
	if (n <= length() && n > 0)
	{
		Node* tmp = head;
		for (int i = 0; i < (n - 1); ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(p, tmp->next);
		return true;

	}
	else if (n == 0)
	{
		add_first(p);
		return true;
	}
	else
	{
		return false;
	}
}

bool List::delp(int n)
{
	if (n < length() && n > 0)
	{
		Node* tmp = head;
		for (int i = 0; i < (n - 1); ++i)
		{
			tmp = tmp->next;
		}
		Node* tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;

		return true;

	}
	else if (n == length())
	{
		del_last();
		return true;
	}
	else if (n == 0)
	{
		Node* tmp = head;
		head = tmp->next;
		delete tmp;
	}

	else
	{
		return false;
	}
}

void List::reverse()
{
	if (length() > 2)
	{
		Node* tmp = nullptr;
		Node* tmp2 = head->next;
		while (tmp2->next != nullptr)
		{
			head->next = tmp;
			tmp = head;
			head = tmp2;
			tmp2 = tmp2->next;
		}
		head->next = tmp;
		tmp = head;
		head = tmp2;
		tmp2->next = tmp;
	}
	else if (length() == 2)
	{
		Node* tmp = head->next;
		tmp->next = head;
		head->next = nullptr;
		head = tmp;
	}
}

void List::remove_if(bool(*f)(int))
{
	Node* tmp = head;
	int i = 0;
	while (tmp->next != nullptr)
	{

		if (f(tmp->data))
		{
			tmp = tmp->next;
			delp(i);
		}
		else
		{
			tmp = tmp->next;
			++i;
		}
	}
}

void List::del()
{
	if (head != nullptr)
	{
		while (head != nullptr)
		{
			Node* tmp;
			tmp = head;
			head = head->next;
			delete tmp;
		}
		head = nullptr;
	}
}

List& List::operator=(const List& l)
{
	if (&l != this)
	{
		this->head = copy(l.head);
	}
	return *this;
}
