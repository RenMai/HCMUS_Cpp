#include<iostream>
using namespace std;

void swap_int(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
struct tree
{
	int data;
	tree *left;
	tree *right;

};
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int high(tree *a, int h)
{
	if (a == NULL) return h;
	else return max(high(a->left, h + 1), high(a->right, h + 1));
}
void add_node(tree *&a,int k)
{
	if (a == NULL)
	{
		a = new tree;
		a->data = k;
		a->left = NULL;
		a->right = NULL;
	}
	else if (a->data > k)
		add_node(a->left, k);
	else add_node(a->right, k);
	
}
void display(tree *a, int level)
{
	if (a != NULL)
	{
		for (int i = 0; i < level; ++i)
			cout << "  ";
		cout << a->data << endl;
		if (a->left) display(a->left, level + 1);
		if (a->right) display(a->right, level + 1);
	}
}
void print_tree(tree *a, int h)
{
	if (a != NULL)
	{
		cout << a->data<<" ";
		if (a->left) print_tree(a->left, h + 1);
		if (a->right) print_tree(a->right, h + 1);
	}
}
void delete_tree(tree *&a, int k)
{
	if (a == NULL) return;
	if (a->data > k) delete_tree(a->left, k);
	else if (a->data < k) delete_tree(a->right, k);
	else
	{
		if (a->left == NULL && a->right == NULL)
		{
			tree * del = a;
			a = NULL;
			delete del;
		}
		else if (a->left == NULL)
		{
			tree *del = a;
			a = a->right;
			delete del;
		}
		else if (a->right == NULL)
		{
			tree *del = a;
			a = a->left;
			delete del;
		}
		else
		{
			tree *del = a->right;
			while (del->left != NULL)
				del = del->left;
			swap_int(a->data, del->data);
			delete_tree(a, del->data);
		}

	}
}
int count_leaf(tree *a, int n)
{
	if (a->left != NULL)
		n += count_leaf(a->left, 0);
	if (a->right != NULL)
		n += count_leaf(a->right, 0);
	if (a->left == NULL && a->right == NULL)
		return 1;
	else return n;
}
void copy_tree(tree *a, tree *&b)
{
	if (a == NULL)
	{
		b = NULL;
		return;
	}
	else add_node(b, a->data);
	if (a->right) copy_tree(a->right, b->right);
	if (a->left) copy_tree(a->left, b->left);
}
int main()
{
	tree *a = NULL;
	tree *b = NULL;
	add_node(a, 5);
	add_node(a, 7);
	add_node(a, 3);
	add_node(a, 11);
	add_node(a, 4);
	add_node(a, 6);
	add_node(a, 9);
	add_node(a, 12);
	delete_tree(a, 7);
	//print_tree(a, 0);
	cout<< endl;
	//cout << high(a, 0) << endl;
	copy_tree(a, b);
	display(a, 0);
	//cout << "------------------------------" << endl;
	//display(b, 0);
	cout << count_leaf(a, 0) << endl;

	system("pause");
	return 0;
}