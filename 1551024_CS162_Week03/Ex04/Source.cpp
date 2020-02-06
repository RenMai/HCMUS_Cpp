#include "linkedlist.h"

void InputLinkedListFile(Node* &p, ifstream & fin)
{
	int data;
	Node* cur=NULL;
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
void OutputLinkedListFile(Node* joined, ofstream &fout)
{
	fout << joined->data << endl;
}
Node* FindLast(Node* p)
{
	Node* tmp = p;
	while (tmp->pNext != NULL)
	{
		tmp = tmp->pNext;
	}
	return tmp;
}
Node* CheckCommonNode(Node *p1, Node* p2)
{
	Node* tmp1 = p1;
	Node* tmp2 = p2;
	while (tmp1 != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp1 == tmp2)
			{
				return tmp1;
			}
			tmp2 = tmp2->pNext;
		}
		tmp2 = p2;
		tmp1 = tmp1->pNext;
	}
	return NULL;
}
Node* FindOrder(Node* p, int data)
{
	while (p != NULL)
	{
		if (p->data == data)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
void Remove(Node* &p)
{
	Node* tmp = p;
	while (p != NULL)
	{
		p = p->pNext;
		delete tmp;
		tmp = p;
	}
}
void Remove(Node* &p, Node* joined)
{
	Node* tmp = p;
	while (p != joined)
	{
		p = p->pNext;
		delete tmp;
		tmp = p;
	}
	p = NULL;
}

void main()
{
	Node* ph1 = NULL;
	Node* ph2 = NULL;
	ifstream fin, fin1;
	ofstream fout;
	fin.open("inputlist1.txt");
	if (fin.is_open())
	{
		InputLinkedListFile(ph1, fin);
	}
	else
	{
		cout << "Your input.txt is not valid, please check again" << endl;
	}
	fin1.open("inputlist2.txt");
	if (fin1.is_open())
	{
		InputLinkedListFile(ph2, fin1);
	}
	else
	{
		cout << "Your input.txt is not valid, please check again" << endl;
	}
	Node* hold;
	hold = FindOrder(ph1, 26);
	Node* last = FindLast(ph2);
	if (hold != NULL)
	{
		last->pNext = hold;
	}
	Node* find;
	find = CheckCommonNode(ph1, ph2);
	fout.open("joined.txt");
	if (fout.is_open())
	{
		if (find != NULL)
		{
			OutputLinkedListFile(find, fout);
		}
		else
		{
			fout << "Two linked list dont have any common nodes" << endl;
		}
	}
	else
	{
		cout << "your output file is not valid, please check again!" << endl;
	}
	Remove(ph2, find);
	Remove(ph1);
}