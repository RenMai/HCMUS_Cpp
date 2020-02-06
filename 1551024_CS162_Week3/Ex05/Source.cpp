#include "Header.h"

void InputLinkedListFile(ifstream &fin, Node* &p)
{
	int data;
	Node* cur = NULL;
	fin >> data;
	while (!fin.eof())
	{
		if (p == NULL)
		{
			p = new Node;
			p->data = data;
			p->pNext = NULL;
			cur = p;
		}
		else
		{
			cur->pNext = new Node;
			cur = cur->pNext;
			cur->data = data;
			cur->pNext = NULL;
		}
		fin >> data;
	}
}
void InsertEvenBefore(Node* &p)
{
	Node* hold;
	Node* tmp = p;
	int k = 2;
	if (p != NULL)
	{
		hold = new Node;
		if (hold != NULL)
		{
			hold->data = k;
			hold->pNext = p;
			p = hold;
			k += 2;
		}
		else
			return;
	}
	if (tmp != NULL)
	{
		while (tmp->pNext != NULL)
		{
			hold = new Node;
			if (hold != NULL)
			{
				hold->data = k;
				hold->pNext = tmp->pNext;
				tmp->pNext = hold;
				tmp = hold->pNext;
				k += 2;
			}
			else
				return;
		}
	}
}
void Display(Node* p)
{
	while (p != NULL)
	{
		cout << "Number" << ":" << p->data << endl;
		p = p->pNext;
	}
}
void OutputLinkedListFile(ofstream &fout, Node* p)
{

	while (p != NULL)
	{
		fout << "Number:" << p->data << endl;
		p = p->pNext;
	}
}
void Remove(Node* &p)
{
	Node* tmp = p;
	while (tmp != NULL)
	{
		p = p->pNext;
		delete tmp;
		tmp = p;
	}
}

void main()
{
	Node* p = NULL;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	if (fin.is_open())
	{
		InputLinkedListFile(fin, p);
	}
	else
	{
		cout << "Your 'input.txt' is not valid please try again!" << endl;
	}
	fin.close();
	InsertEvenBefore(p);
	Display(p);
	fout.open("output_even_inserted.txt");
	if (fout.is_open())
	{
		OutputLinkedListFile(fout, p);
	}
	else
	{
		cout << "your linked list is not valid, please check again!" << endl;
	}
	fout.close();
	Remove(p);
}