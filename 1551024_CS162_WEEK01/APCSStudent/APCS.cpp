#include "APCS.h"

bool checkleap(Apcs x)
{
	if (x.Year % 400 == 0) return true;
	else if (x.Year % 100 == 0) return false;
	else if (x.Year % 4 == 0) return true;
	else return false;
}

bool checkdob(Apcs x)
{
	if (x.Day <= 0 || x.Day > 31 || x.Year <= 0 || x.Month <= 0 || x.Month > 12 || ((x.Month == 2) && x.Day > 29))
		return false;
	if (!checkleap(x))
	{
		if (x.Month == 2)
		{
			if (x.Day >= 29) return false;
		}
	}
	if (x.Month == 4 || x.Month == 6 || x.Month == 9 || x.Month == 11)
	{
		if (x.Day == 31) return false;
	}
	return true;
}
void input(Apcs &x)
{
	cout << "Enter student ID: ";
	cin.getline(x.ID, 8, '\n');
	cout << "Enter student full name: ";
	cin.getline(x.Name, 31, '\n');
	cout << "Enter stundent address: ";
	cin.getline(x.Address, 51, '\n');
	cout << "Enter student date of birth: " << endl;
	cout << "Enter day: ";
	cin >> x.Day;
	cout << "Enter month: ";
	cin >> x.Month;
	cout << "Enter year: ";
	cin >> x.Year;
	cout << "Enter student grade: ";
	cin >> x.Grade;
}
void input_text(Apcs &x)
{
	ifstream fin;
	fin.open("input.txt");
	fin.getline(x.ID, 8, '\n');
	fin.getline(x.Name, 31, '\n');
	fin.getline(x.Address, 51, '\n');
	fin >> x.Day;
	fin >> x.Month;
	fin >> x.Year;
	fin >> x.Grade;
	fin.close();
}
void output(Apcs x)
{
	cout << "Student ID: ";
	cout << x.ID << endl;
	cout << "Student full name: ";
	cout << x.Name << endl;
	cout << "Stundent address: ";
	cout << x.Address << endl;
	cout << "Student date of birth: " <<x.Day<<"/"<<x.Month<<"/"<<x.Year<< endl;
	cout << "Student grade: ";
	cout << x.Grade << endl;
}
void output_text(Apcs x)
{
	ofstream fout;
	fout.open("output.txt");
	fout << "Student ID: ";
	fout << x.ID << endl;
	fout << "Student full name: ";
	fout << x.Name << endl;
	fout << "Stundent address: ";
	fout << x.Address << endl;
	fout << "Student date of birth: " << x.Day << "/" << x.Month << "/" << x.Year << endl;
	fout << "Student grade: ";
	fout << x.Grade << endl;
	fout.close();
}
char classify(Apcs x)
{
	char a;
	if (x.Grade <= 2) a = 'A';
	else if (x.Grade <= 4) a = 'B';
	else if (x.Grade <= 6) a = 'C';
	else if (x.Grade <= 8) a = 'D';
	else a = 'F';
	return a;
}