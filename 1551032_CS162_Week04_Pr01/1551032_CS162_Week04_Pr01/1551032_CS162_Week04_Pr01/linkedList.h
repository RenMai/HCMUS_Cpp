#pragma once

#include<iostream>
#include<math.h>

using namespace std;

struct Node
{
	int data;
	Node*next;
};

class linkedList
{
private:
	Node* head1;
	Node* head2;
public:
	
	linkedList(){ head1 = NULL; head2 = NULL; }
	void Insert2LinkList();
	void sortInsert();	
	void Display2List();
	void sumUptoI();
	void SeparateList(Node*&fhead,Node*&shead);
	void CombineList(Node*fhead, Node*shead, Node*&head1);
	void Joining();
	void computeToInteger(Node*&head,int &result);
	void integerRepresent(int result,Node*&head);
	
};

