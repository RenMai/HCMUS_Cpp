#include"Book.h"

void main()
{
	char a;
	int menu;
	Book* book = NULL;
	cout << "Menu\n";
	cout << "1. Initialization.\n";
	cout << "2. Input a book.\n";
	cout << "3. Sell a book.\n";
	cout << "4. Find a book.\n";
	cout << "5. Remove all book whose stock level is less than a threshold k.\n";
	cout << "6. Exit program.\n";
	cin >> menu;
	while (menu != 6)
	{
		switch (menu)
		{
		case 1:
			init(book);
			break;
		case 2:
			input(book);
			break;
		case 3:
			sell(book);
			break;
		case 4:
			find(book);
			break;
		case 5:
			remove(book);
		case 6:
			break;
		default:
			cout << "Your input is invalid. Please try again.\n";
			system("pause");
			break;
		}
		cout << "Menu\n";
		cout << "1. Initialization.\n";
		cout << "2. Input a book.\n";
		cout << "3. Sell a book.\n";
		cout << "4. Find a book.\n";
		cout << "5. Remove all book whose stock level is less than a threshold k.\n";
		cout << "6. Exit program.\n"; 
		cin >> menu;
	}
	removeall(book);
}