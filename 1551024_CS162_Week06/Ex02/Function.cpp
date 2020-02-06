#include "Header.h"


Student::Student()
{
	ID = 0;
	Name = "";
	Next = NULL;
	Prev = NULL;
}

Table::Table()
{
	N = 0;
	Head = NULL;

	ifstream inp;
	inp.open("Text.txt");

	while (!inp.eof())
	{
		int _ID = 0;
		string _Name = "";
		inp >> _ID;
		inp.get();
		getline(inp, _Name);
		if ((_ID == 0) && (_Name == ""))
		{
			break;
		}
		if (Head == NULL)
		{
			Head = new Student;
			Head->ID = _ID;
			Head->Name = _Name;
			Head->Next = Head;
			Head->Prev = Head;
			N++;
		}
		else
		{
			Student *Current = Head->Prev;
			Current->Next = new Student;
			Current->Next->Prev = Current;
			Current = Current->Next;
			Current->ID = _ID;
			Current->Name = _Name;
			Current->Next = Head;
			Head->Prev = Current;
			N++;
		}
	}
	inp.close();
}

Table::~Table()
{
	delete Head;
}



void Table::LuckyMan()
{
	if (Head == NULL)
	{
		ofstream outp;
		outp.open("Output.txt");
		outp << "NULL";
		outp.close();
		outp.open("Log.txt");
		outp << "NULL";
		outp.close();
		return;
	}

	srand(time(0));
	ofstream outp;
	outp.open("Log.txt");
	int Times = 0;
	while (N != 1)
	{
		Times++;
		int Step = rand() % 6 + 1;
		outp << "Dice value of #" << Times << " toss: " << Step << endl;
		while (Step != 0)
		{
			Head = Head->Next;
			Step--;
		}
		outp << "Leaving student:" << endl;
		outp << "ID: " << Head->ID << endl;
		outp << "Name: " << Head->Name << endl;
		outp << endl;

		Student *Current = Head->Prev;
		Head = Head->Next;
		delete Current->Next;
		Current->Next = Head;
		Head->Prev = Current;
		N--;
	}
	outp.close();

	outp.open("Output.txt");
	outp << "Lucky man:" << endl;
	outp << Head->ID << endl;
	outp << Head->Name;
	outp.close();
}