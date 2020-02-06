#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
struct list
{
	node *head;
	node *tail;
};
void print_list(list *a)
{
	for (node *b = a->head; b != NULL; b = b->next)
	{
		cout << b->data << endl;
	}
}
void insert_mid(list *a, int k)
{
	node * t = new node;
	t->data = k;
	for (node *i = a->head; i != NULL; i = i->next)
	{
		if (i->data == 2)
		{
			node* n = i->next;
			i->next = t;
			t->next = n;
		}
	}

}
void insert_head(list *a, int k)
{
	node *t = new node;
	t->data = k;
	t->next = a->head;
	a->head = t;
}
void insert_end(list *a)
{
	a->tail->next = new node;
	node *t = a->tail->next;
	a->tail = t;
	t->data = 9;
	t->next = NULL;

}
void delete_node(list *a, int k)
{
	if (k == a->head->data)
	{
		node *t = a->head;
		a->head = a->head->next;
		delete t;
	}
	else if (k == a->tail->data)
	{
		node *t = a->head;
		while (t->next->next != NULL) t = t->next;
		a->tail = t;
		t = t->next;
		delete t;
		a->tail->next = NULL;
	}
	else
	for (node*t = a->head; t != NULL; t = t->next)
	{
		if (t->next->data == k)
		{
			node *i = t->next;
			t->next = t->next->next;
			delete i;
			return;
		}
	}
}
int main()
{
	list *a = new list;
	a->head = new node;
	a->head->data = 6;
	a->tail = a->head;
	node *t = a->head;

	for (int i = 0; i < 6; ++i)
	{
		t->next = new node;
		t = t->next;
		t->data = i;
		a->tail = t;
		t->next = NULL;
	}
	insert_end(a);
	insert_mid(a, 7);
	insert_head(a, 11);
	delete_node(a, 4);

	print_list(a);

	system("pause");

	return 0;
}