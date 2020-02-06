//Student ID:1551025
//Student name: Lieng The Phy
//Exercise 03:  insert nodes numbered 2, 4, 6, 8, 10… before 
//every nodes in the list of Problem 2
#include "Function.h"
void main()
{
	Node* p=NULL;
	ifstream fin;
	ofstream fout;
	fin.open("3_input.txt");
	if(fin.is_open())
	{
		InputLinkedListFile(fin,p);
	}
	else
	{
		cout<<"Your 'input.txt' is not valid please try again!"<<endl;
	}
	fin.close();
	InsertEvenBefore(p);
	Display(p);
	fout.open("3_output_even_inserted.txt");
	if(fout.is_open())
	{
		OutputLinkedListFile(fout,p);
	}
	else
	{
		cout<<"your linked list is not valid, please check again!"<<endl;
	}
	fout.close();
	Remove(p);
}