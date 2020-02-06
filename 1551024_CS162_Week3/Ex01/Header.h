#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

struct Node
{
	int data;
	Node* pNext;

};
void init(Node *pH);
void add1st(Node *&pH);
void addlast(Node *&pH, Node *&last);
void addbeforeY(Node *&pH, Node *&last);
void displayNode(Node *pH);
void del1st(Node *&pH, Node *&last);
void dellast(Node *&pH, Node *&last);
void delX(Node *&pH, Node *&last);
void checkX(Node *&pH, Node *&last);
void printPrime(Node *&pH, Node *&last);
void sumPrime(Node *&pH, Node *&last);
void sortA(Node *&pH, Node *&last);