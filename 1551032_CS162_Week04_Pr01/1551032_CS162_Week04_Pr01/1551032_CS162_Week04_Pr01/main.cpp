#include"linkedlist.h"

using namespace std;

int main()
{
	linkedList list;

	list.Insert2LinkList();
	cout << endl;
	cout << " 1 / " << endl;
	list.sortInsert();
	cout << endl;
	list.Display2List();
	cout << endl;
	cout << " 2 / " << endl;
	list.sumUptoI();
	cout << endl;
	Node*head1 = NULL;
	Node*head2 = NULL;
	Node*head3 = NULL;
	cout << " 3/ " << endl;
	list.SeparateList(head1,head2);
	cout << endl;
	cout << " 4 / " << endl;
	list.CombineList(head1, head2, head3);
	cout << endl;
	Node*head4 = NULL;
	int result;
	cout << " 5 / " << endl;
	list.computeToInteger(head4, result);
	cout << endl;
	Node*head5 = NULL;
	cout << " 6 / " << endl;
	list.integerRepresent(result, head5);
	cout << endl;
}