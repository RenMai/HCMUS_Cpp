#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int key;
	char* Student;
	int Gender;
	int height;
	Node* left;
	Node* right;
	Node(int ID, char* s, int gender)
	{
		key = ID;
		Student = s;
		Gender = gender;
		left = NULL;
		right = NULL;
		height = 1;
	}
};
int GetHeight(Node *node);
int GetBalance(Node *node);
int GetBoy(Node *node);
int GetGirl(Node *node);
Node* RightRot(Node* z);
Node* LeftRot(Node *z);
Node* Insert(Node* node, int key, char *s, int gender);
Node* SearchX(Node* node, int x);
void Input(Node* &root);
void Output(Node* root);
void Menu(Node*& root);