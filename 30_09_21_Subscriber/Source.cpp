#include<iostream>
#include<fstream>
#include <list>
#include "Subscriber.h"

using namespace std;

void print_menu();

void menu(int p, list<Subscriber> &l);

void add(list<Subscriber> &l);

void del(string tel, list<Subscriber>& l);

void print_tel(string tel, list<Subscriber>& l);

ostream& operator << (ostream& st, list<Subscriber> l);

int main()
{
	setlocale(LC_ALL, "Russian");

	list<Subscriber> l;
	Subscriber a;
	ifstream fin("database.txt");
	int N;
	//fin >> N;
	for (int i = 0; i < 3; ++i)
	{
		fin >> a;
		l.push_back(a);
	}
	list<Subscriber>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
		cout << *i << endl;
	}

	int p = 0;
	do 
	{
		system("cls");
		print_menu();
		cin >> p;
		menu(p, l);
		system("pause");
	} while (p != 0);
	
	for (i = l.begin(); i != l.end(); ++i)
	{
		cout << *i << endl;
	}

	return EXIT_SUCCESS;
}

void print_menu()
{
	cout << "0 : Выход" << endl;
	cout << "1 : Добавить абонента" << endl;
	cout << "2 : Удалить абонента по номеру" << endl;
	cout << "3 : Вывести имя и адрес по номеру" << endl;
	cout << "4 : Вывести всю базу" << endl;
}

void menu(int p, list<Subscriber> &l)
{
	switch (p)
	{
	case 1:
	{
		add(l);
		break;
	}
	case 2:
	{
		string tel;
		getline(cin, tel); // костыль очищающий буфер ввода cin
		cout << "Telephone:" << endl;
		getline(cin, tel);
		del(tel, l);
		break;
	}
	case 3:
	{
		string tel;
		getline(cin, tel); // костыль очищающий буфер ввода cin
		cout << "Telephone:" << endl;
		getline(cin, tel);
		print_tel(tel, l);
		break;
	}
	case 4:
	{
		cout << l;
	}
	default:
		break;
	}
}

void add(list<Subscriber> &l)
{
	string n;
	string ad;
	string t;
	getline(cin, n); // костыль очищающий буфер ввода cin
	cout << "Name:" << endl;
	getline(cin, n);
	cout << "Address:" << endl;
	getline(cin, ad);
	cout << "Telephone:" << endl;
	getline(cin, t);
	Subscriber a(n, ad, t);
	l.push_back(a);
}

void del(string tel, list<Subscriber>& l)
{

	list<Subscriber>::iterator i;
	for (i = l.begin(); i != l.end();)
	{
		if (i->telephone == tel)
		{
			i = l.erase(i); 
		}
		else
		{
			++i;
		}
	}
}

void print_tel(string tel, list<Subscriber>& l)
{
	list<Subscriber>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
		if (i->telephone == tel)
		{ 
			cout << *i << endl;
		}
	}
}

ostream& operator << (ostream& st, list<Subscriber> l)
{
	list<Subscriber>::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
	{
		st << "Name:" << i->name << endl << "Address:" << i->address << endl << "Telephone:" << i->telephone << endl << endl;
	}
	return st;
}