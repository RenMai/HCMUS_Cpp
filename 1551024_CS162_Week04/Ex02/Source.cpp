
#include "book.h"

int main()
{
	int menu = 0;
	Book *listbook = NULL;
	Book bookH, *lastbook = NULL;
	cout << "Menu\n"
		<< "1.Initialize the bookstore.\n"
		<< "2.Add a new book.\n"
		<< "3.Sell a book.\n"
		<< "4.Find a book.\n"
		<< "5.Remove books with stock level less than a threshold k.\n"
		<< "6.Exit program. \n";
	cin >> menu;

	while (menu != 6){
		switch (menu)
		{
		case 1:
			bookH.init(listbook);
			break;
		case 2:
			bookH.add(listbook, lastbook);
			break;
		case 3:
			bookH.sell(listbook);
			break;
		case 4:
			bookH.find(listbook);
			break;
		case 5:
			bookH.remove(listbook);
			break;
		case 6:
			break;
		default:
			cout << "Invalid.\n";
		}
		cout << "Menu\n"
			<< "1.Initialize the bookstore.\n"
			<< "2.Add a new book.\n"
			<< "3.Sell a book.\n"
			<< "4.Find a book.\n"
			<< "5.Remove books with stock level less than a threshold k.\n"
			<< "6.Exit program. \n";
		cin >> menu;
	}
	bookH.terminate(listbook);
	return 0;
}