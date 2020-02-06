#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	int data;
	int occur;
	Node* pL;
	Node* pR;
};
void AddNode(Node* &p, int k)
{
	if (p = NULL)
	{
		p = new Node;
		p->data = k;
		p->occur = 1;
		p->pL = NULL;
		p->pR = NULL;
	}
	return;
}
void FindNode(Node*  pRoot, int temp)
{
	if (pRoot == NULL)
	{
		AddNode(pRoot, temp);
		return;
	}
	if (pRoot->data == temp)
	{
		++(pRoot->occur);
		return;
	}
	if (temp < pRoot->data)
		FindNode(pRoot->pL, temp);
	else FindNode(pRoot->pR, temp);
}
void LoadTree(Node* pRoot)
{
	int temp;
	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> temp;
			FindNode(pRoot, temp);
		}
		fin.close();
	}
	return;
}
ofstream fout;
void Inorder(Node* pRoot)
{
	if (pRoot != NULL)
	{
		Inorder(pRoot->pL);
		cout << pRoot->data << " - Appearances: " << pRoot->occur << endl;
		Inorder(pRoot->pR);
	}
	else
		return;
}
void output(Node* pRoot)
{
	fout.open("output.txt");
	if (fout.is_open())
	{
		Inorder(pRoot);
		fout.close();
	}
	return;
}
int main()
{
	Node* pRoot = NULL;
	LoadTree(pRoot);
	output(pRoot);
	return 0;
}