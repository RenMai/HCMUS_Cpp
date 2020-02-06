#include<iostream>
#include"linkedList.h"
using namespace std;


int main()
{
	linkedList sol;
	sol.inputFromFile();
	sol.Display();
	cout<<endl;

	sol.InsertOddNumber();
	sol.Display();
	sol.printToFile("input_even_inserted.txt");
	cout<<endl;

	Node*head1=NULL;
	sol.JoinList(head1);

	sol.checkCommonNode(head1);

	cout<<endl;

	Node*head2=NULL;
	
	sol.createLoop(head2);

	sol.checkLoop(head2);

	return 0;
}