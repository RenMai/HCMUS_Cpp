#pragma once
#include "Number.h"
#include "Calc.h"
#include <string>

void Input(Number *&New_Number);


void main()
{
	Number *A = new Number;
	Input(A);
	Number *B = new Number;
	Input(B);
	Number *Plus = PlusZ(A, B);
	Number *Minus = MinusZ(A, B);
	Number *Multiply = MultiplyZ(A, B);
	Number *Div = DivZ(A, B);
	Number *Mod = ModZ(A, B);
	cout << endl;
	cout << A << " + " << B << " = " << Plus << endl;
	cout << A << " - " << B << " = " << Minus << endl;
	cout << A << " * " << B << " = " << Multiply << endl;
	cout << A << " / " << B << " = " << Div << endl;
	cout << A << " % " << B << " = " << Mod << endl;
	system("pause");
}

void Input(Number *&New_Number)
{
	string String_Number;
	int Minus = 0;
	cout << "Input a Number: ";
	getline(cin, String_Number);
	for (int i = 0; i < String_Number.length(); i++)
	{
		switch (String_Number[i])
		{
		case '-':
			Minus++;
			break;
		default:
			Digit *New_Digit = new Digit;
			New_Digit->Data = String_Number[i] - '0';
			New_Number->PushTail(New_Digit);
		}
	}
	if (Minus % 2 == 1)
	{
		New_Number->isPos = false;
	}
}