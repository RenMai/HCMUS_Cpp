#include"Linkedlist.h"

void Init(Node* &pH)
{
	Node* temp = pH;
	while (temp != NULL)
	{
		pH = pH->pNext;
		delete temp;
		temp = pH;
	}
}

void display(Node* &pH)
{
	Node* temp = pH;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->pNext;
	}
	delete (temp);
}

void findX(Node* &pH)
{
	Node* temp = pH;
	int k = 0, x;
	cout << "Enter x: " << endl;
	cin >> x;
	while (temp != NULL)
	{
		if (x == temp->data)
		{
			cout << "X locate at slot " << k << endl;
			return;
		}
		temp = temp->pNext;
		++k;
	}
	cout << "Can't find X" << endl;
	delete(temp);
}
void addfirst(Node* &pH)
{
	Node* temp;
	cout << "Enter an integer you want to add" << endl;
	cin >> temp->data;
	temp->pNext = pH;
}