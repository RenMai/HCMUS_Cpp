#pragma once
#include<fstream>
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* pNext;
};
void Remove(Node* &p);
void Remove(Node* &p,Node* joined);
Node* FindOrder(Node* p,int data);
Node* FindLast(Node* p);
void Display(Node* p);
int ChangeOrder(Node* &p);
Node* CheckCommonNode(Node *p1,Node* p2);
void InputLinkedListFile(Node* &p,ifstream &fin);
void OutputLinkedListFile(Node* joined,ofstream &fout);