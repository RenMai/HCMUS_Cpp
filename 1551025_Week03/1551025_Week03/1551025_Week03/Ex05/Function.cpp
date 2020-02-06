#include"Function.h"
void InputLinkedListFile(Node* &p,ifstream &fin)
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
Node* FindLast(Node* p)
{
	Node* tmp=p;
	while(tmp->pNext!=NULL)
	{
		tmp=tmp->pNext;
	}
	return tmp;
}
Node* CheckLoop(Node *p1)
{
	Node* tmp1=p1;
	Node* tmp2=p1;
	if(tmp1->pNext==tmp1)
	{
		return tmp1;
	}
	while(tmp1!=NULL)
	{
		while(tmp2!=tmp1)
		{
			if(tmp1->pNext==tmp2)
			{
				return tmp1;
			}
			tmp2=tmp2->pNext;
			if(tmp1->pNext==tmp2)
			{
				return tmp1;
			}
		}
		tmp2=p1;
		tmp1=tmp1->pNext;
	}
	return NULL;
}
Node* FindOrder(Node* p,int data)
{
	while(p!=NULL)
	{
		if(p->data==data)
		{
			return p;
		}
		p=p->pNext;
	}
	return NULL;
}
void Remove(Node* &p,Node* last)
{
	Node* tmp=p;
	while(p!=last)
	{
		p=p->pNext;
		delete tmp;
		tmp=p;
	}
	if(p!=NULL)
	{
		p=p->pNext;
		delete tmp;
		tmp=p;
	}
}