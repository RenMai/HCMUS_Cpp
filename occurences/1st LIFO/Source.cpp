#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* pNext;
};
void push(Node* &pH, int t)
{
	Node* cur;
	cur = new Node;
	cur->data = t;
	cur->pNext = pH;
	pH = cur;
}
Node* pop(Node* &pH)
{
	Node* cur;
	if (pH != NULL)
	{
		cur = pH;
		pH = pH->pNext;
	}
	return cur;
}
void enqueue(Node* &pT, int t)
{
	pT->pNext= new Node;
	pT=pT->pNext
	pT->data = t;
	pT->pNext = NULL;
}
void dequeque(Node* &PH)
{

}