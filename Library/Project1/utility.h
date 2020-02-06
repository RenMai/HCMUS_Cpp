#pragma once
#include <string>
using namespace std;

struct date
{
	int dd, mm, yy;			//day,month,year
	int day_of_month();		//return the max day of that month
	bool leap();			//leap year return 1, else return 0
	bool check();			//valid->return true, else return false
};
struct maxID
{
	int userID, questID;
};

string encrypt(const string &raw);		// return the encrypted string
void input_yesno(const string &message, bool &input);				// display string, prompt bool input (with value checking)
void input_number(const string &message, int min, int max, int &input);		// display string, prompt int input (with value checking)
void input_string(const string &message, string &input);		// display string, prompt input from user