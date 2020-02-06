#include "function.h"
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
bool Even(int n)
{
	if(n%2==0)
	{
		return true;
	}
	return false;
}
void DeleteAllEven(Node* &p)
{
	Node* pre;
	Node* tmp=p;
	while(tmp!=NULL)
	{
		if(Even(tmp->data)&&tmp==p)
		{
			p=p->pNext;
			delete tmp;
			tmp=p;
		}
		else if(Even(tmp->data))
		{
			pre->pNext=tmp->pNext;
			delete tmp;
			tmp=pre->pNext;
		}
		else
		{
			pre=tmp;
			tmp=tmp->pNext;
		}
	}
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
	while(p!=NULL)
	{
		fout<<"Number:"<<p->data<<endl;
		p=p->pNext;
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