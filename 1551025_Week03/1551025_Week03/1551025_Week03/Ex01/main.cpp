//Student ID:1551025
//Student name: Lieng The Phy
//Problem 01:  Please write a program to input the linked list 
// reverse the linked list, and output the nodes in the new order 
#include "function.h"
void main()
{
	Node* p=NULL;
	ifstream fin;
	ofstream fout;
	fin.open("1_input.txt");
	if(fin.is_open())
	{
		InputLinkedListFile(fin,p);
	}
	else
	{
		cout<<"Your 'input.txt' is not valid please try again!"<<endl;
	}
	fin.close();
	Reverse(p);
	Display(p);
	fout.open("1_output_reversed.txt");
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