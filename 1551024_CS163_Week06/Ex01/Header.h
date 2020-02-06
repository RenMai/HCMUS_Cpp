#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
	int height;
	Node(int k)
	{
		key = k;
		left = NULL;
		right = NULL;
		height = 1;
	}
};
int GetHeight(Node *node);
int GetHeight2(Node *node);
int GetBalance(Node *node);
int GetHeight2(Node *node);
Node* Insert(Node* node, int key);
Node* SearchX(Node* node, int x);
Node* RightRot(Node* z);
Node* LeftRot(Node *z);
Node* DeleteX(Node* node, int key);
void PreOrder(Node *node);
void InOrder(Node *node);
void PostOrder(Node *node);
void Menu(int &choice);
void SwapX(int &a, int &b);