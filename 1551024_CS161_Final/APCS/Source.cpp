#include"APCS.h"

void main()
{
	int n;
	int IDstudent;
	char namestudent[100];
	cout << "Enter student ID:";
	cin >> IDstudent;
	cout << "Enter student name:";
	cin.getline(namestudent, 100, '\n');
	cout << "Enter the number of course student enrolled:";
	cin >> n;
	APCS apcs;
	for (int i = 1; i <= n; ++i)
	{
		cout << "Enter course ID " << n << ": ";
		cin >> apcs.courid[i];
		cout << "Enter course name: ";
		cin.getline()
	}

}