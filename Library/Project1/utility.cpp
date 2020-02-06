#include "utility.h"
#include <iostream>
using namespace std;

//return the max day of that month
int date::day_of_month()
{
	switch (mm)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		return 31; break;
	case 4:case 6:case 9:case 11:
		return 30; break;
	case 2:
		if (leap())
			return 29;
	}
	return 28;
}
//leap year return 1, else return 0
bool date::leap()
{
	if (!(mm % 400)) return true;
	if (!(mm % 100)) return false;
	if (!(mm % 4)) return true;
	return false;
}
//valid->return true, else return false
bool date::check()
{
	if (mm < 1 || mm>12 || dd > day_of_month() || dd < 1)
		return false;
	return true;
}

string encrypt(const string &raw)
{
	string b;
	for (int i = 0; i < raw.size(); ++i)
		b.push_back(raw[i] - 2);
	return b;
}
void input_number(const string &message, int min, int max, int &input)
{
	cout << message;
	while (true)
	{
		cin >> input;
		// check if format is correct
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid number format. Please type again: ";
		}
		// check range
		else if (input < min)
			cout << "Your number must be at least " << min << ". Please type again: ";
		else if (input > max)
			cout << "Your number must be at most " << max << ". Please type again: ";
		else
			break;
	}
	cin.get();
}
void input_yesno(const string &message, bool &input)
{
	cout << message;
	string choice;
	while (true)
	{
		cin >> choice;
		// make the string lower case
		for (int i = 0; i < choice.length(); ++i)
			choice[i] = tolower(choice[i]);
		// check if value is valid
		if (choice == "yes" || choice == "y")
		{
			input = true;
			return;
		}
		if (choice == "no" || choice == "n")
		{
			input = false;
			return;
		}
		cout << "Invalid value. Please type again: ";
	}
}
void input_string(const string &message, string &input)
{
	cout << message;
	getline(cin, input);
}