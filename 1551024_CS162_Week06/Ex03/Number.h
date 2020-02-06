#pragma once
#include <iostream>

using namespace std;

struct Digit
{
	Digit();
	int ID;
	int Data;
	Digit *Next;
	Digit *Prev;
};

class Number
{
public:
	Number();
	~Number();

	bool isPos;

	friend ostream & operator<<(ostream &Output, Number *&Current_Number);

	void PushHead(Digit *&New_Digit);
	void PushTail(Digit *&New_Digit);

	Digit *PopHead();
	Digit *PopTail();

	Digit *Head;
	Digit *Tail;
};