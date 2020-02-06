#include "23tree.h"
using namespace std;

int main(int argc, char** argv)
{

	int v[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 37, 36, 35, 34 };
	int size = sizeof(v) / sizeof(int);
	int n;
	Tree23 tree;

	Node23 *inserted_node = 0;
	/* Build this tree:
	(34,  40)
	/    |    \
	20    36    (60,80)
	/ \    / \   /  | \
	10 30 35 37 50 70  90 */
	for (int i = 0; i < size; i++) {

		inserted_node = tree.insert(v[i]);
	}

	cout << "Menu: \n 1. Output tree in-order.\n 2. Find the Width of tree.\n 3. Find the min value of the tree.\n 4. Find the max value of the tree.\n 5.Find the height of the tree" << endl;
	cin >> n;
	switch (n)
	{
	case 1: tree.Traverse([](int x) { cout << x << ' '; }); break;
	case 2: cout << "The width of the tree is: " << tree.count_leaf() << endl; break;
	case 3: cout << "The min value of the tree is: " << tree.getMin() << endl; break;
	case 4: cout << "The max value of the tree is: " << tree.getMax() << endl; break;
	case 5: cout << "The height of the tree is: " << tree.height() << endl; break;
	default:
		cout << "Input valid" << endl;
		break;
	}

	return 0;

}