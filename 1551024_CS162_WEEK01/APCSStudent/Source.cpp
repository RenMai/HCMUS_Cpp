#include "APCS.h"

int main()
{
	char abc;
	float a = 0;
	cout << "Enter a to input the student info by keyboard; Enter b to input the student info by text : " << endl;
	cin >> abc;
	cin.get();
	Apcs apcs[1];
	if (abc == 'a')
	{
		input(apcs[0]);
	}
	else if (abc == 'b') input_text(apcs[0]);
	else
	{
		cout << "Your input is valid. Please try again." << endl;
		return 0;
	}
	if (!checkdob(apcs[0]))
	{
		cout << "Your input(DoB) is valid. Please try again." << endl;
		return 0;
	}
	output(apcs[0]);
	output_text(apcs[0]);
	cout << "Classify: " << classify(apcs[0]) << endl;

	return 0;
}