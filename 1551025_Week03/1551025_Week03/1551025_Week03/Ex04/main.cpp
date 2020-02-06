//Student ID:1551025
//Student name: Lieng The Phy
//Exercise 04: Given two linked list A and B. Find common nodes at which
//A and B are joined.
#include"Function.h"
void main()
{
	Node* ph1=NULL;
	Node* ph2=NULL;
	ifstream fin,fin1;
	ofstream fout;
	fin.open("4_inputlist1.txt");
	if(fin.is_open())
	{
		InputLinkedListFile(ph1,fin);
	}
	else
	{
		cout<<"Your input.txt is not valid, please check again"<<endl;
	}
	fin1.open("4_inputlist2.txt");
	if(fin1.is_open())
	{
		InputLinkedListFile(ph2,fin1);
	}
	else
	{
		cout<<"Your input.txt is not valid, please check again"<<endl;
	}
	Node* hold;
	hold=FindOrder(ph1,26);
	Node* last=FindLast(ph2);
	if(hold!=NULL)
	{
		last->pNext=hold;
	}
	Node* find;
	find=CheckCommonNode(ph1,ph2);
	fout.open("4_joined.txt");
	if(fout.is_open())
	{
		if(find!=NULL)
		{
			OutputLinkedListFile(find,fout);
		}
		else
		{
			fout<<"Two linked list dont have any common nodes"<<endl;
		}
	}
	else
	{
		cout<<"your output file is not valid, please check again!"<<endl;
	}
	Remove(ph2,find);
	Remove(ph1);
}
