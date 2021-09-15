#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int d = 0, Node* n = nullptr) : data(d), next(n) {}

};

bool f(int a)
{
	return a % 2 == 0 ? true : false;
}

struct List
{
	Node* head;
	
	List()
	{
		head = nullptr;
	}

	int length()
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

	bool indexValid(int n)
	{
		return n >= 0 && n < length();
	}

	void add_first(int d)
	{
		Node* tmp;
		tmp = new Node(d, head);
		head = tmp; 
	}

	void print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}

	Node* last()
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		return tmp;
	}

	Node* prelast()
	{
		Node* tmp = head;
		while (tmp->next->next != nullptr)
		{
			tmp = tmp->next;
		}
		return tmp;
	}

	Node* get_ptr(int n)
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

	void add_after_first(int d)
	{
		Node* tmp;
		tmp = new Node(d, head->next);
		head->next = tmp;
	}

	void add_last(int d)
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(d, nullptr);
	}

	void del_last()
	{
		Node* tmp = head;
		while (tmp->next->next != nullptr)
		{
			tmp = tmp->next;
		}
		delete tmp->next;
		tmp->next = nullptr;
	}

	bool insertp(int n, int p)
	{
		if(n <= length() && n > 0)
		{
			Node* tmp = head;
			for(int i = 0; i < (n -1); ++i)
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

	bool delp(int n)
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

	void reverse()
	{
		if (length() > 2)
		{
			Node* tmp = head;
			Node* tmp2 = head->next;
			Node* tmp3 = head->next->next;
			while (tmp3->next != nullptr)
			{
				tmp2->next = tmp;
				tmp = tmp2;
				tmp2 = tmp3;
				tmp3 = tmp3->next;
			}
			tmp2->next = tmp;
			tmp3->next = tmp2;
			head->next = nullptr;
			head = tmp3;
		}
		else if(length() == 2)
		{
			Node* tmp = head->next;
			tmp->next = head;
			head->next = nullptr;
			head = tmp;
		}
		
	}

	void remove_if(bool (*f)(int))
	{
		Node* tmp = head;
		int i = 0;
		while(tmp->next != nullptr)
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
	
};


int main()
{
	List l;
	l.add_first(5);
	l.add_first(4);
	l.add_first(3);
	l.add_first(2);
	l.add_first(1);
	l.print();

	cout << l.last()->data << endl;
	cout << l.prelast()->data << endl;
	cout << l.get_ptr(2)->data << endl;
	l.add_after_first(9);
	l.print();
	l.add_last(6);
	l.print();
	l.del_last();
	l.print();
	l.insertp(0, 99);
	l.insertp(4, 99);
	l.insertp(l.length(), 99);
	l.print();
	l.delp(l.length());
	l.delp(4);
	l.delp(0);
	l.delp(1);
	l.print();
	l.reverse();
	l.print();
	l.remove_if(f);
	l.print();

	
	
	return EXIT_SUCCESS;
}