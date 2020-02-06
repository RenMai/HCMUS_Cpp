#include "linkedlist.h"

void input(Node* &pH)
{
	Node* cur = NULL;
	int t;
	ifstream fin;
	fin.open("input.txt");
	while (!fin.eof())
	{
		fin >> t;
		if (pH == NULL)
		{
			pH = new Node;
			pH->data = t;
			pH->pNext = NULL;
			cur = pH;
		}
		else {
			cur->pNext = new Node;
			cur = cur->pNext;
			cur->data = t;
			cur->pNext = NULL;
		}
	}
	fin.close();
}
void reverse(Node* &pH)
{
	Node* pPre = NULL;
	Node* temp = pH;
	Node* pNext = pH;
	while (temp != NULL)
	{
		pNext = temp->pNext;
		temp->pNext = pPre;
		pPre = temp;
		temp = pNext;
		pH = pPre;
	}
}
void display(Node* pH)
{
	Node* cur = pH;
	ofstream fout;
	fout.open("output_even_deleted");
	while (cur != NULL)
	{
		cur = cur->pNext;	
		if (cur == NULL) break;
		fout << cur->data << "\n";
	}
	fout.close();
}
void removeAll(Node* &pH)
{
	Node* temp = pH;
	while (pH != NULL)
	{
		pH = pH->pNext;
		delete temp;
		temp = pH;
	}
}
void delete_evens(struct Node *&pH)
{
	struct Node *temp, *step, *prev=NULL;

	if (pH == NULL)
		return;

	while (pH != NULL && pH->data % 2 == 0)
	{
		temp = pH;
		pH = pH->pNext;
		delete temp;
	}

	step = pH;

	while (step != NULL)
	{
		if (step->data % 2 == 0)
		{
			temp = step;
			step = step->pNext;
			prev->pNext = step;
			delete temp;
		}
		else
		{
			prev = step;
			step = step->pNext;
		}
	}
	step = NULL;
}


void main()
{
	Node* pH = NULL;
	input(pH);
	reverse(pH);
	delete_evens(pH);
	display(pH);
	removeAll(pH);
}