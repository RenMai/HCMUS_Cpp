#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

struct Node
{
	int data;
	Node*next;
};

class linkedList
{
private:
	Node*head;
public:
	linkedList(){head=NULL;}
	void inputFromFile();
	void Display();
	void InsertOddNumber();
	void JoinList(Node*&head1);
	void checkCommonNode(Node*head1);
	void createLoop(Node*&head1);
	void checkLoop(Node*head1);
	void printToFile(string filename);
	
	
};

