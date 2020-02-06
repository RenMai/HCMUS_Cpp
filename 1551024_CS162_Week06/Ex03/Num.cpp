#pragma once
#include "Number.h"

Digit::Digit()
{
	ID = 0;
	Data = 0;
	Next = NULL;
	Prev = NULL;
}

Number::Number()
{
	isPos = true;
	Head = NULL;
	Tail = NULL;
}

Number::~Number()
{
	while (Head != NULL)
	{
		Digit *Temp = Head;
		Head = Head->Next;
		delete Temp;
	}
}

ostream & operator<<(ostream &Output, Number *&Current_Number)
{
	if (Current_Number == NULL)
	{
		Output << "NULL";
		return Output;
	}
	if (!Current_Number->isPos)
	{
		Output << "-";
	}
	Digit *Current_Digit = Current_Number->Head;
	while (Current_Digit != NULL)
	{
		Output << Current_Digit->Data;
		Current_Digit = Current_Digit->Next;
	}
	return Output;
}

void Number::PushHead(Digit *&New_Digit)
{
	if ((Head == NULL) && (Tail == NULL))
	{
		Head = New_Digit;
		Tail = New_Digit;
	}
	else
	{
		Head->Prev = New_Digit;
		New_Digit->Next = Head;
		Head = Head->Prev;
	}
	Digit *Current = Head;
	int _ID = 0;
	while (Current != NULL)
	{
		_ID++;
		Current->ID = _ID;
		Current = Current->Next;
	}
}

void Number::PushTail(Digit *&New_Digit)
{
	if ((Head == NULL) && (Tail == NULL))
	{
		Head = New_Digit;
		Tail = New_Digit;
		Tail->ID = 1;
	}
	else
	{
		New_Digit->ID = Tail->ID + 1;
		Tail->Next = New_Digit;
		New_Digit->Prev = Tail;
		Tail = Tail->Next;
	}
}

Digit *Number::PopHead()
{
	if (Head == NULL)
	{
		return NULL;
	}
	Digit *Temp = Head;
	while (Temp != NULL)
	{
		Temp->ID--;
		Temp = Temp->Next;
	}
	Temp = Head;
	Head = Head->Next;
	if (Head != NULL)
	{
		Head->Prev = NULL;
	}
	else
	{
		Head = NULL;
		Tail = NULL;
	}
	Temp->Next = NULL;
	Temp->Prev = NULL;
	Temp->ID = 0;
	return Temp;
}

Digit *Number::PopTail()
{
	if (Tail == NULL)
	{
		return NULL;
	}
	Digit *Temp = Tail;
	Tail = Tail->Prev;
	if (Tail != NULL)
	{
		Tail->Next = NULL;
	}
	else
	{
		Head = NULL;
		Tail = NULL;
	}
	Temp->Next = NULL;
	Temp->Prev = NULL;
	Temp->ID = 0;
	return Temp;
}

