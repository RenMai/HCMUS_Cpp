#include "Header.h"

int GetHeight(Node *node)
{
	return (node == NULL) ? 0 : (node->height);
}

int GetBalance(Node *node)
{
	if (node == NULL)
		return 0;
	return (GetHeight(node->left) - GetHeight(node->right));
}

int GetBoy(Node *node)
{
	if (node == NULL)
		return 0;
	if (node->Gender == 1)
		return 1 + GetBoy(node->left) + GetBoy(node->right);
	return GetBoy(node->left) + GetBoy(node->right);
}

int GetGirl(Node *node)
{
	if (node == NULL)
		return 0;
	if (node->Gender == 0)
		return 1 + GetGirl(node->left) + GetGirl(node->right);
	return GetGirl(node->left) + GetGirl(node->right);
}

Node* RigtRot(Node* z)
{
	Node *y = z->left;
	Node *T3 = y->right;
	y->right = z;
	z->left = T3;

	z->height = max(GetHeight(z->left), GetHeight(z->right)) + 1;
	y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;

	return y;
}

Node* LeftRot(Node *z)
{
	Node *y = z->right;
	Node *T2 = y->left;

	y->left = z;
	z->right = T2;

	z->height = max(GetHeight(z->left), GetHeight(z->right)) + 1;
	y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;

	return y;
}

Node* Insert(Node* node, int key, char *s, int gender)
{
	if (node == NULL)
	{
		Node* cur = new Node(key, s, gender);
		return cur;
	}

	if (key < node->key)
		node->left = Insert(node->left, key, s, gender);
	else
		node->right = Insert(node->right, key, s, gender);

	node->height = max(GetHeight(node->left), GetHeight(node->right)) + 1;

	int balance = GetBalance(node);


	if (balance > 1 && key < node->left->key)
		return RigtRot(node);

	if (balance < -1 && key > node->right->key)
		return LeftRot(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = LeftRot(node->left);
		return RigtRot(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = RigtRot(node->right);
		return LeftRot(node);
	}

	return node;
}

void Input(Node* &root)
{
	int ID, gender;
	do
	{
		cout << "Enter ID (0 if you wanna stop): ";
		cin >> ID;

		if (ID != 0)
		{
			do
			{
				cout << "Gender (0 for girl, 1 for boy): ";
				cin >> gender;
			} while (gender != 0 && gender != 1);

			char *s = new char[101];
			cin.ignore();
			cout << "Enter student: ";
			cin.getline(s, 100, '\n');

			root = Insert(root, ID, s, gender);
		}
		cout << endl;
	} while (ID != 0);
}

Node* SearchX(Node* node, int x)
{
	if (node == NULL)
		return 0;
	if (x == node->key)
		return node;
	if (x < node->key)
		return SearchX(node->left, x);
	else
		return SearchX(node->right, x);
}

void Output(Node* root)
{
	if (root == NULL)
		return;
	cout << "ID: " << root->key << endl;
	cout << "Name: " << root->Student << endl;
	cout << "Gender: " << ((root->Gender == 0) ? "Girl" : "Boy") << endl;
	cout << "Height: " << root->height << endl << endl;
	Output(root->left);
	Output(root->right);
}

void Update(Node* node, int k)
{
	if (SearchX(node, k))
	{
		Node *cur = SearchX(node, k);
		cout << "ID: " << cur->key << endl;
		cout << "Name: " << cur->Student << endl;
		cout << "Gender: " << ((cur->Gender == 0) ? "Girl" : "Boy") << endl;
		cout << "Height: " << cur->height << endl << endl;

		int gender;
		do
		{
			cout << "New one (0 for girl, 1 for boy): ";
			cin >> gender;
		} while (gender != 0 && gender != 1);
		cur->Gender = gender;

		cin.ignore();
		cout << "Enter new student: ";
		cin.getline(cur->Student, 100, '\n');

	}
	else
		cout << "K doesn't exist" << endl;
	return;
}

void Menu(Node*& root)
{
	int choice;
	cout << "0.Quit" << endl;
	cout << "1.Input." << endl;
	cout << "2.Output." << endl;
	cout << "3.Update." << endl;
	cout << "4.Find the difference between the number of girls and the number of boys among all the students with id smaller than k." << endl;
	do
	{
		cout << endl << "Menu: ";
		cin >> choice;
	} while (choice < 0 || choice > 4);
	if (choice == 0)
		return;
	else if (choice == 1)
		Input(root);
	else if (choice == 2)
		Output(root);
	else if (choice == 3)
	{
		cout << "Enter ID u wanna update: ";
		int c;
		cin >> c;
		Update(root, c);
	}
	else if (choice == 4)
	{
		int k;
		cout << "Enter k: ";
		cin >> k;
		Node *cur = SearchX(root, k);
		cout << "The result : " << GetGirl(cur->left) + GetGirl(cur->right) - GetBoy(cur->left) - GetBoy(cur->right) << endl;
	}
	Menu(root);
}
