#include"Book.h"

void init(Book* &book)
{
	if (book == NULL) 
		Book* book = new Book;
	Book* temp = book;
	while (book != NULL)
	{
		book = book->pNext;
		delete temp;
		temp = book;
	}
}
void input(Book* &b)
{
	if (b==NULL) 
		Book* b= new Book;
	Book* book = new Book;
	Book* temp = b;
	Book* a = b;
	cin.get();
	cout << "Input Title: ";
	cin.getline(book->Title, 201, '\n');
	cout << "Input ISBN: ";
	cin.getline(book->ISBN, 11, '\n');
	cout << "Input Author: ";
	cin.getline(book->Author, 41, '\n');
	cout << "Input Language: ";
	cin.getline(book->Language, 31, '\n');
	cout << "Input Publish year: ";
	cin >> book->Year;
	cout << "Input Price: ";
	cin >> book->Price;
	cout << "Input Stock level: ";
	cin >> book->Stock;
	while (a != NULL)
	{
		if (_stricmp(a->ISBN, book->ISBN) == 0)
		{
			a->Stock = book->Stock;
			return;
		}
		else
		{
			a = a->pNext;
		}
	}
	if (b == NULL)
	{
		b = book;
	}
	else
	{
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = book;
	}
}
void sell(Book* &b)
{
	Book* book = b;
	char is[11];
	cin.get();
	cout << "Enter the ID of the book: ";
	cin.getline(is, 11, '\n');
	while (book != NULL)
	{
		if (_stricmp(book->ISBN, is) == 0)
		{
			if (book->Stock == 0)
				cout << "Out of stock" << endl;
			else
			{
				cout << "Name of the book: " << book->Title << endl;
				cout << "Price of the book: " << book->Price << endl;
				--book->Stock;
				break;
			}
		}
		else
			book = book->pNext;
		if (book == NULL)
			cout << "Can't find book!";
	}
}
void find(Book* b)
{
	Book* book = b;
	int t = 0;
	char k[201], h[201];
	cout << "Enter the name of the book:" << endl;
	cin.get();
	cin.getline(k, 201, '\n');
	while (book != NULL)
	{
		for (int i = 0; i < strlen(book->Title); ++i)
		{
			if (book->Title[i] == k[0])
			{
				for (int j = 0; j < strlen(k); ++j)
				{
					if (book->Title[i + j] != k[j])
						break;
					if (j == strlen(k) - 1)
					{
						cout << "ID of the book: " << book->ISBN << endl;
						cout << "Name of the book: " << book->Title << endl;
						++t;
					}

				}
			}
		}
		book = book->pNext;
	}
	if (t == 0) cout << "Can't find book!\n";
}
void remove(Book* &b)
{
	int k;
	Book* book = b;
	cout << "Enter k:" << endl;
	cin.get();
	cin >> k;
	if (b != NULL)
	{
		if (b->Stock < k)
		{
			Book *tmp = b;
			b = b->pNext;
			delete tmp;
		}
	}
	else return;
	Book *prev = b, *cur = b->pNext;
	while (cur != NULL)
	{
		if (b->Stock < k)
		{
			Book *tmp = cur;
			if (cur->pNext == NULL)
			{
				delete tmp;
			}
			else
			{
				cur = cur->pNext;
				delete tmp;
			}
		}
		else
		{
			prev = cur;
			cur = cur->pNext;
		}
	}
}
void removeall(Book* &b)
{
	while (b != NULL)
	{
		Book *temp = b;
		b = b->pNext;
		delete temp;
	}
}