#include"Header.h"

void init(Node *pH)
{
	Node *tmp = pH;
	while (tmp != NULL){
		pH = pH->pNext;
		delete tmp;
		tmp = pH;
	}
}
void add1st(Node *&pH)
{
	cout << "Enter the value you want to add:";
	if (pH == NULL)
	{
		pH = new Node;
		pH->pNext = NULL;
		cin >> pH->data;
	}
	else
	{
		Node *temp = new Node;
		cin >> temp->data;
		temp->pNext = pH;
		pH = temp;

	}
}
void displayNode(Node *&pH, Node *&last)
{
	Node *temp = pH;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->pNext;
	}
}