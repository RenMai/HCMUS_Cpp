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
void DeleteAllEven(Node* &p);
void Display(Node* p);
bool Even(int n);
void OutputLinkedListFile(ofstream &fout,Node* p);
void Remove(Node* &p);