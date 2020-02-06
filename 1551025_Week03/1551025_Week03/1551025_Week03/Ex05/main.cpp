//Student ID:1551025
//Student name: Lieng The Phy
//Exercise 05: Given a singly linked list, 
//you are to dertermine whether it contains a loop or not.
#include"Function.h"
void main()
{
	ifstream fin;
	ofstream fout;
	Node *ph=NULL;
	fin.open("5_input.txt");
	if(fin.is_open())
	{
		InputLinkedListFile(ph,fin);
	}
	else
	{
		cout<<"Your input.txt is not valid, please check again"<<endl;
	}
	Node* hold;
	Node* last;
	last=FindLast(ph);
	hold=FindOrder(ph,26);
	if(hold!=NULL)
	{
		last->pNext=hold;
	}
	Node* check=CheckLoop(ph);
	fout.open("5_loop.txt");
	if(fout.is_open())
	{
		if(check!=NULL)
		{
			fout<<"YES"<<endl;
		}
		else
		{
			fout<<"NO"<<endl;
		}
	}
	else
	{
		cout<<"Your output file is not valid, please check again!"<<endl;
	}
	Remove(ph,last);
}