#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

struct tree
{
	string key;
	string content;
	tree *left;
	tree *right;

};

void add_node(tree *&a, string key, string content);
vector<string> split(const string &s, char delim)
{
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) tokens.push_back(item);
	return tokens;
}
void swap_int(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void read_file(tree *&a)
{
	string b;
	vector<string> temp;
	ifstream fin;
	fin.open("Dictionary.dict");
	while (!fin.eof())
	{
		getline(fin, b);
		temp = split(b, '\t' );
		cout << temp[0] << "-" << temp[1] << endl;
		//add_node(a, temp[0], temp[1]);
	}
	fin.close();
}
void add_node(tree *&a, string key, string content)
{
	if (a == NULL)
	{
		a = new tree;
		a->key = key;
		a->content = content;
		a->left = NULL;
		a->right = NULL;
	}
	else if (a->key > key)
		add_node(a->left, key, content);
	else add_node(a->right, key, content);

}
void display(tree *a, int level)
{
	if (a != NULL)
	{
		for (int i = 0; i < level; ++i)
			cout << "  ";
		cout << a->key << endl;
		if (a->left) display(a->left, level + 1);
		if (a->right) display(a->right, level + 1);
	}
}
void delete_tree(tree *&a, string k)
{
	if (a == NULL) return;
	if (a->key > k) delete_tree(a->left, k);
	else if (a->key < k) delete_tree(a->right, k);
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
			strcpy(a->key, del->key);
			delete_tree(a, del->key);
		}	

	}
}
string search_by_key(tree *a, string key)
{
	if (a == NULL) return "";
	if (a->key > key) search_by_key(a->left, key);
	else if (a->key < key) search_by_key(a->right, key);
	else return a->content;
}
string search_by_content(tree *a, string content)
{
	if (a == NULL) return "";
	if (a->content > content) search_by_content(a->left, content);
	else if (a->content < content) search_by_content(a->right, content);
	else return a->key;
}
int main()
{
	int choice;
	tree *dictionary;
	read_file(dictionary);
	cin >> choice;

	return 0;
}