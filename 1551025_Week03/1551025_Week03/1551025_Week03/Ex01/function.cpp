#include"function.h"
void InputLinkedListFile(ifstream &fin,Node* &p)
{
	int data;
	Node* cur;
	fin>>data;
	while(!fin.eof())
	{
		if(p==NULL)
		{
			p=new Node;
			p->data=data;
			p->pNext=NULL;
			cur=p;
		}
		else
		{
			cur->pNext=new Node;
			cur=cur->pNext;
			cur->data=data;
			cur->pNext=NULL;
		}
		fin>>data;
	}
}
void Reverse(Node* &p)
{
	Node* pre=NULL;
	Node* tmp=p;
	Node* next;
	while(tmp!=NULL)
	{
		next=tmp->pNext;
		tmp->pNext=pre;
		pre=tmp;
		tmp=next;
	}
	p=pre;
}
void Display(Node* p)
{
	while(p!=NULL)
	{
		cout<<"Number"<<":"<<p->data<<endl;
		p=p->pNext;
	}
}
void OutputLinkedListFile(ofstream &fout,Node* p)
{
	if(fout.is_open())
	{
		while(p!=NULL)
		{
			fout<<"Number:"<<p->data<<endl;
			p=p->pNext;
		}
	}
}
void Remove(Node* &p)
{
	Node* tmp=p;
	while(tmp!=NULL)
	{
		p=p->pNext;
		delete tmp;
		tmp=p;
	}
}