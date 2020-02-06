#include"Header.h"

void main()
{
	Node *root = NULL;
	int key;
	cout << "Enter the first value: ";
	cin >> key;
	root = Insert(root, key);
	int choice1;
	Menu(choice1);
	while (choice1 >= 1 && choice1 <= 5)
	{
		switch (choice1)
		{
		case 1:
			while (key != 0)
			{
				cout << "Enter key (Enter 0 if you wanna stop): ";
				cin >> key;
				if (key == 0) break;
				root = Insert(root, key);
			}
			system("pause");
			system("cls");
			Menu(choice1);
			break;
		case 2:
			cout << "Enter the value you want to search: ";
			int x;
			cin >> x;
			if (SearchX(root, x))
				cout << "x exist in the tree" << endl;
			else
				cout << "x doesn't exist in the tree" << endl;
			system("pause");
			system("cls");
			Menu(choice1);
			break;
		case 3:
			cout << "1. Preoder." << endl << "2. Inoder." << endl << "3. Postoder." << endl;
			int choice2;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				cout << endl << "Preorder: ";
				PreOrder(root);
				system("pause");
				system("cls");
				Menu(choice1);
				break;
			case 2:
				cout << endl << "Inorder: ";
				InOrder(root);
				system("pause");
				system("cls");
				Menu(choice1);
				break;
			case 3:
				cout << endl << "Postorder: ";
				PostOrder(root);
				system("pause");
				system("cls");
				Menu(choice1);
				break;
			default:
				break;
			}
			break;
		case 4:
			cout << "Enter the value you wanna delete:";
			cin >> key;
			root = DeleteX(root, key);
			system("pause");
			system("cls");
			Menu(choice1);
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}