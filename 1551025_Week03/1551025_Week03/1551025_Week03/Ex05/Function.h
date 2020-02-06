#pragma once
#include<fstream>
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* pNext;
};
void Remove(Node* &p,Node* last);
Node* FindOrder(Node* p,int data);
Node* FindLast(Node* p);
void Display(Node* p,Node *last);
Node* CheckLoop(Node *p);
void InputLinkedListFile(Node* &p,ifstream &fin);