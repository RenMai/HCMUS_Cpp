//Student ID:1551025
//Student name: Lieng The Phy
//Exercise 02: Delete all nodes with even values
#include "function.h"
void main()
{
	Node* p=NULL;
	ifstream fin;
	ofstream fout;
	fin.open("2_input.txt");
	if(fin.is_open())
	{
		InputLinkedListFile(fin,p);
	}
	else
	{
		cout<<"your linked list is not valid, please check again!"<<endl;
	}
	fin.close();
	DeleteAllEven(p);
	Display(p);
	fout.open("2_output_even_deleted.txt");
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