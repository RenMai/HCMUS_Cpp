#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
	string key;
	string def;
	Node* pL;
	Node* pR;
};

class BTS
{
public:
	BTS()
	{
		pRoot = NULL;
	}
	~BTS()
	{
		delete pRoot;
	}
	bool CreateNode(Node* p, string a, string b)
	{
		if (!p)
		{
			p = new Node;
			if (!p)
			{
				cout << "Error 1!" << endl;
				return false;
			}
			p->key = a;
			p->def = b;
			p->pL = NULL;
			p->pR = NULL;
			return true;
		}
		else
		{
			cout << "Error 2!" << endl;
			return false;
		}
	}
	void Locate(Node* p, string a, string b)
	{
		if (p = NULL)
		{
			if (CreateNode(p, a, b))
				return;
			else
			{
				cout << "Error 3!" << endl;
				return;
			}
		}
		if (a < p->key)
			Locate(p->pL, a, b);
		if (a > p->def)
			Locate(p->pR, a, b);
	}
	void Load()
	{
		string a, b;
		ifstream fin;
		fin.open("emotional-dictionary.txt");
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				fin >> a;
				getline(fin, b, '\n');
				Locate(pRoot, a, b);
			}
			fin.close();
		}
		else
		{
			cout << "Error 4! Error opening file" << endl;
			return;
		}
	}
	Node* SearchKey(string s, Node* p)
	{
		if (!p)
			return NULL;
		if (s == p->key)
			return p;
		if (s < p->key)
			SearchKey(s, p->pL);
		if (s > p->key)
			SearchKey(s, p->pR);
	}
	Node* SearchContent(string s, Node* p)
	{
		if (!p)
		{
			return NULL;
		}
		if (s == p->def)
			return p;
		if (s < p->def)
			SearchContent(s, p->pL);
		if (s > p->def)
			SearchContent(s, p->pR);
	}
	void Search()
	{
		int cmd = -1;
		while (cmd != 0)
		{
			cout << "Search function. Enter a number to search: " << endl << "   1. By key" << endl << "   2. By content" << endl;
			cout << "   0. Cancel search" << endl;
			cin >> cmd;
			string s;
			cout << "Enter search term: ";
			cin >> s;
			if (cmd == 1)
			{
				if (SearchKey(s, pRoot))
					cout << s << " : " << SearchKey(s, pRoot)->def << endl;
				else
					cout << "Not Found!" << endl;
			}
			if (cmd == 2)
			{
				if (SearchContent(s, pRoot))
					cout << SearchContent(s, pRoot)->key << endl;
				else
					cout << "Not Found!" << endl;
			}
		}
	}
	void Remove(Node* p)
	{
		string s;
		Node* temp = NULL;
		cout << "Enter key: ";
		cin >> s;
		if (SearchKey(s, pRoot))
			temp = SearchKey(s, pRoot);
		else
		{
			cout << "Not Found" << endl;
			return;
		}
		if (temp->pR == NULL && temp->pL == NULL)
		{
			delete temp;
			return;
		}
		if (temp->pL && !(temp->pR))
		{
			Node* del = temp->pL;
			temp->key = temp->pL->key;
			temp->def = temp->pL->def;
			temp->pL = temp->pL->pL;
			temp->pR = temp->pL->pR;
			delete del;
			return;
		}
		if (temp->pR && !(temp->pL))
		{
			Node* del = temp->pR;
			temp->key = temp->pR->key;
			temp->def = temp->pR->def;
			temp->pL = temp->pR->pL;
			temp->pR = temp->pR->pR;
			delete del;
			return;
		}
		//use MoL or moR function
		Node* del = MoL(temp->pL);
		temp->def = del->def;
		temp->key = del->key;
		delete del;
	}
	Node* MoL(Node* p)
	{
		if (p->pR)
			MoL(p->pR);
		else
			return p;
	}
	Node* moR(Node* p)
	{
		if (p->pL)
			moR(p->pL);
		else
			return p;
	}
private:
	Node* pRoot;
};

int main()
{
	BTS A;
	A.Load();
	int cmd = -1;
	while (cmd != 0)
	{
		cout << "Enter command: " << endl << "   1. Search  2. Remove  3. Manage fav" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
		default:
			break;
		}
	}
	return 0;
}