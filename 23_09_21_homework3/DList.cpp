#include<iostream>
#include "DList.h"


bool DList::indexValid(int n)
{
	if (n >= 0 && n < length())
	{
		return true;
	}
	return false;
}

int DList::length()
{

	int i = 0;
	DNode* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++i;
	}
	return i;
}

void DList::add_first(int d)
{
	if (head == nullptr)
	{
		DNode* tmp;
		tmp = new DNode(d, nullptr, nullptr);
		head = tmp;
		tail = tmp;
	}
	else if(tail == head && head != nullptr)
	{
		DNode* tmp;
		tmp = new DNode(d, head, nullptr);
		head->prev = tmp;
		head = tmp;
		head->next = tail;
	}
	else
	{
		DNode* tmp;
		tmp = new DNode(d, head, nullptr);
		head->prev = tmp;
		head = tmp;
	}
	
}

void DList::add_last(int d)
{
	if (head == nullptr)
	{
		add_first(d);
	}
	else if (tail == head && head != nullptr)
	{
		DNode* tmp = tail->next;
		tmp = new DNode(d, nullptr, tail);
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		DNode* tmp = tail->next;
		tmp = new DNode(d, nullptr, tail);
		tail->next = tmp;
		tail = tmp;
	}

}

DNode* DList::last()
{
	return tail;
}

DNode* DList::prelast()
{
	return tail->prev;
}

void DList::print()
{
	if (head == nullptr)
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		DNode* p = head;
		while (p != nullptr)
		{
			std::cout << p->data << "\t";
			p = p->next;
		}
		std::cout << std::endl;
	}
}

void DList::reprint()
{
	if (tail == nullptr)
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		DNode* p = tail;
		while (p != nullptr)
		{
			std::cout << p->data << "\t";
			p = p->prev;
		}
		std::cout << std::endl;
	}
}

void DList::add_after_first(int d)
{
	if (head == nullptr)
	{
		DNode* tmp;
		tmp = new DNode(d, nullptr, nullptr);
		head = tmp;
		tail = tmp;
	}
	else if (tail == head && head != nullptr)
	{
		DNode* tmp = tail->next;
		tmp = new DNode(d, nullptr, tail);
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		DNode* tmp;
		tmp = new DNode(d, head->next, head);
		head->next = tmp;
		tmp->next->prev = tmp;

	}
}

void DList::del_last()
{
	if (head != nullptr)
	{
		if (head == tail)
		{
			DNode* tmp = head;
			delete tmp;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			DNode* tmp = prelast();
			delete tmp->next;
			tmp->next = nullptr;
			tail = tmp;
		}
	}
	
}

void DList::del_second()
{
	if (head->next != nullptr)
	{
		if (head->next == tail)
		{
			DNode* tmp = head;
			delete tmp->next;
			tmp->next = nullptr;
			tail = tmp;
		}
		else
		{
			DNode* tmp = head->next;
			head->next = head->next->next;
			head->next->prev = head;
			delete tmp;
		}
	}
}

void DList::del_first()
{
	if (head != nullptr)
	{
		if (head == tail)
		{
			DNode* tmp = head;
			delete tmp;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			DNode* tmp = head;
			head->next->prev = nullptr;
			head = head->next;
			delete tmp;
		}
	}
}

bool DList::insertp(int n, int p)
{
	if (n < length() && n > 0)
	{
		DNode* tmp = head;
		for (int i = 0; i < (n - 1); ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new DNode(p, tmp->next, tmp);
		tmp->next->next->prev = tmp->next;
		return true;

	}
	else if (n == 0)
	{
		add_first(p);
		return true;
	}
	else if(n == length())
	{
		add_last(p);
		return true;
	}
	else
	{
		return false;
	}
}

bool DList::delp(int n)
{
	if (n < (length() - 1) && n > 0)
	{
		DNode* tmp = head;
		for (int i = 0; i < n; ++i)
		{
			tmp = tmp->next;
		}
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		delete tmp;
		return true;

	}
	else if (n == 0)
	{
		del_first();
		return true;
	}
	else if (n == (length()-1))
	{
		del_last();
		return true;
	}
	else
	{
		return false;
	}
}

void DList::reverse()
{
	if (length() >= 2)
	{
		DNode* tmp = head;
		DNode* tmp2 = nullptr;
		while (tmp->next != nullptr)
		{
			tmp2 = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp2;
			tmp = tmp->prev;
		}
		tmp->next = tmp->prev;
		tmp->prev = nullptr;
		tail = head;
		head = tmp;
	}
	
}

void DList::remove_if(bool(*f)(int))
{
	DNode* tmp = head;
	int i = 0;
	while (tmp != nullptr)
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
