#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	int data;
	Node* pNext;
};
void InputLinkedListFile(ifstream &fin,Node* &p);
void Reverse(Node* &p);
void Display(Node* p);
void OutputLinkedListFile(ofstream &fout,Node* p);
void Remove(Node* &p);