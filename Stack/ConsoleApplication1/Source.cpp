#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
struct stack
{
	node *top;
	stack() :top(NULL){}
};
void push_stack(stack *&st, int k)
{
	node * h = new node;
	h->data = k;
	h->next = st->top;
	st->top = h;
}
void print_stack(stack *st)
{
	node *cur = st->top;
	while (cur)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}
int pop_stack(stack*st)
{
	if (st == NULL) return 0;
	else{
		int k;
		node* h = st->top;
		st->top = st->top->next;
		k = h->data;
		delete h;
		return k;
	}
}
void res(stack *&a)
{
	stack *b = new stack();
	while (a->top)
		push_stack(b, pop_stack(a));
	a = b;
}
int main()
{
	stack *a;
	a = new stack();
	push_stack(a, 1);
	push_stack(a, 3);
	push_stack(a, 2);
	push_stack(a, 6);
	push_stack(a, 4);
	push_stack(a, 9);
	print_stack(a);
	cout << "--------------------------" << endl;
	res(a);
	print_stack(a);
	return 0;
}