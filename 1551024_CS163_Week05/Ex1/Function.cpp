#include"Header.h"

void Menu(int &choice)
{
	cout << "Enter your choice:" << endl << "1. Insert x to the AVL tree." << endl << "2. Search x in AVL tree." << endl << "3. Print out value,heigt and balance factor." << endl << "4. Delete value X." << endl << "5. Exit." << endl;
	cin >> choice;
}
int GetHeight(Node *node)
{
	return (node == NULL) ? 0 : (node->height);
}

int GetHeight2(Node *node)
{
	if (node == NULL) return 0;
	return max(GetHeight2(node->left), GetHeight2(node->right)) + 1;
}

int GetBalance(Node *node)
{
	if (node == NULL)
		return 0;
	return (GetHeight(node->left) - GetHeight(node->right));
}

int GetBalance2(Node* node)
{
	if (node ==NULL)
		return 0;
	return (GetHeight2(node->left) - GetHeight2(node->right));
}

Node* RightRot(Node* z)
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

Node* Insert(Node* node, int key)
{

	if (node == NULL)
	{
		Node* cur = new Node(key);
		return cur;
	}

	if (key < node->key)
		node->left = Insert(node->left, key);
	else if (key>node->key)
		node->right = Insert(node->right, key);

	node->height = max(GetHeight(node->left), GetHeight(node->right)) + 1;

	int balance = GetBalance(node);


	if (balance > 1 && key < node->left->key)
		return RightRot(node);

	if (balance < -1 && key > node->right->key)
		return LeftRot(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = LeftRot(node->left);
		return RightRot(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = RightRot(node->right);
		return LeftRot(node);
	}

	return node;
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

void PreOrder(Node *node)
{
	if (node == NULL)
		return;
	cout << "Key: " << node->key << endl;
	cout << "Height: " << node->height << endl;
	cout << "Balance Factor: " << GetBalance(node) << endl;
	PreOrder(node->left);
	PreOrder(node->right);
}

void InOrder(Node *node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	cout << "Key: " << node->key << endl;
	cout << "Height: " << node->height << endl;
	cout << "Balance Factor: " << GetBalance(node) << endl;
	InOrder(node->right);
}

void PostOrder(Node *node)
{
	if (node == NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	cout << "Key: " << node->key << endl;
	cout << "Height: " << node->height << endl;
	cout << "Balance Factor: " << GetBalance(node) << endl;
}

void SwapX(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
Node* DeleteX(Node* node, int key)
{
	if (node == NULL) return 0;
	if (node->key > key) node->left = DeleteX(node->left, key);
	else if (node->key < key) node->right = DeleteX(node->right, key);
	else
	{
		if (node->left == NULL && node->right == NULL)
		{
			Node* del = node;
			node = NULL;
			delete del;
		}
		else if (node->left == NULL)
		{
			Node *del = node;
			node = node->right;
			delete del;
		}
		else if (node->right == NULL)
		{
			Node *del = node;
			node = node->left;
			delete del;
		}
		else
		{
			Node* del = node->right;
			while (del->left != NULL)
				del = del->left;
			SwapX(del->key, node->key);
			node = DeleteX(node, del->key);
		}

	}

	node->height = max(GetHeight2(node->left), GetHeight2(node->right)) + 1;

	int balance = GetBalance2(node);


	if (balance > 1 && GetBalance2(node->left) >= 0)
		return RightRot(node);

	if (balance < -1 && GetBalance2(node->right) <= 0)
		return LeftRot(node);

	if (balance > 1 && GetBalance2(node->left) < 0)
	{
		node->left = LeftRot(node->left);
		return RightRot(node);
	}

	if (balance < -1 && GetBalance2(node->right) > 0)
	{
		node->right = RightRot(node->right);
		return LeftRot(node);
	}
	return node;
}
