#pragma once
#include "Calc.h"

void Prepare(Number *&A, Number *&B)
{
	while (A->Tail->ID < B->Tail->ID)
	{
		Digit *Temp = new Digit;
		Temp->Data = 0;
		A->PushHead(Temp);
	}
	while (A->Tail->ID > B->Tail->ID)
	{
		Digit *Temp = new Digit;
		Temp->Data = 0;
		B->PushHead(Temp);
	}
}

void Finish(Number *&A)
{
	while ((A->Head != NULL) && (A->Head->Data == 0))
	{
		Digit *Temp = A->PopHead();
	}
	if (A->Head == NULL)
	{
		Digit *Zero = new Digit;
		A->PushHead(Zero);
	}
}

int LargerThan(Number *&A, Number *&B)
{
	Finish(A);
	Finish(B);
	if (A->Tail->ID > B->Tail->ID)
	{
		return 1;
	}
	else if (A->Tail->ID < B->Tail->ID)
	{
		return 0;
	}
	else
	{
		Digit *Digit_A = A->Head;
		Digit *Digit_B = B->Head;
		while ((Digit_A != NULL) && (Digit_B != NULL))
		{
			if (Digit_A->Data > Digit_B->Data)
			{
				return 1;
			}
			else if (Digit_A->Data < Digit_B->Data)
			{
				return 0;
			}
			else
			{
				Digit_A = Digit_A->Next;
				Digit_B = Digit_B->Next;
			}
		}
		return -1;
	}
}

Number *PlusN(Number *&A, Number*&B)
{
	Prepare(A, B);
	Number *Ans = new Number;
	Digit *Digit_A = A->Tail;
	Digit *Digit_B = B->Tail;
	int Mem = 0;
	while ((Digit_A != NULL) && (Digit_B != NULL))
	{
		Digit *Temp = new Digit;
		Temp->Data = Digit_A->Data + Digit_B->Data + Mem;
		Mem = Temp->Data / 10;
		Temp->Data %= 10;
		Ans->PushHead(Temp);
		Digit_A = Digit_A->Prev;
		Digit_B = Digit_B->Prev;
	}
	if (Mem != 0)
	{
		Digit *Temp = new Digit;
		Temp->Data = Mem;
		Ans->PushHead(Temp);
	}
	Finish(Ans);
	return Ans;
}

Number *MinusN(Number *&A, Number *&B)
{
	int Larger = LargerThan(A, B);
	Number *Ans = new Number;
	Digit *Digit_A=NULL;
	Digit *Digit_B=NULL;
	switch (Larger)
	{
	case -1:
		Digit_A = new Digit;
		Digit_A->Data = 0;
		Ans->PushHead(Digit_A);
		return Ans;
	case 0:
		Digit_A = B->Tail;
		Digit_B = A->Tail;
		Ans->isPos = false;
		break;
	case 1:
		Digit_A = A->Tail;
		Digit_B = B->Tail;
		break;
	}
	Prepare(A, B);
	int Mem = 0;
	while ((Digit_A != NULL) && (Digit_B != NULL))
	{
		Digit *Temp = new Digit;
		if (Digit_A->Data >= Digit_B->Data + Mem)
		{
			Temp->Data = Digit_A->Data - Digit_B->Data - Mem;
			Mem = 0;
		}
		else
		{
			Temp->Data = 10 + Digit_A->Data - Digit_B->Data - Mem;
			Mem = 1;
		}
		Ans->PushHead(Temp);
		Digit_A = Digit_A->Prev;
		Digit_B = Digit_B->Prev;
	}
	Finish(Ans);
	return Ans;
}

Number *MultiplyN(Number *&A, Number *&B)
{
	Number *Ans = new Number;
	Digit *Zero = new Digit;
	Ans->PushHead(Zero);
	Digit *Digit_B = B->Tail;
	int Col = 0;
	Number MultiplyWith[10];
	while (Digit_B != NULL)
	{
		bool Flag = true;
		Number *Temp = new Number;
		Digit *Digit_A = A->Tail;
		int Mem = 0;
		Col++;
		switch (Digit_B->Data)
		{
		case 0:
			Flag = false;
			break;
		default:
			if (MultiplyWith[Digit_B->Data].isPos == false)
			{
				*Temp = (MultiplyWith[Digit_B->Data]);
			}
			else
			{
				while (Digit_A != NULL)
				{
					Digit *Pushing = new Digit;
					Pushing->Data = (Digit_A->Data * Digit_B->Data + Mem) % 10;
					Mem = (Digit_A->Data * Digit_B->Data + Mem) / 10;
					Temp->PushHead(Pushing);
					Digit_A = Digit_A->Prev;
				}
				if (Mem != 0)
				{
					Digit *Pushing = new Digit;
					Pushing->Data = Mem;
					Temp->PushHead(Pushing);
				}
				MultiplyWith[Digit_B->Data] = *Temp;
				MultiplyWith[Digit_B->Data].isPos = false;
			}
			break;
		}
		if (Flag)
		{
			for (int i = 1; i < Col; i++)
			{
				Zero = new Digit;
				Temp->PushTail(Zero);
			}
			Ans = PlusN(Ans, Temp);
		}
		Digit_B = Digit_B->Prev;
	}
	return Ans;
}

void DivModN(Number *&A, Number *&B, Number *&Div, Number *&Mod)
{
	Number *Temp = new Number;
	Digit *_Digit = new Digit;
	Temp->PushHead(_Digit);
	if (LargerThan(B, Temp) == -1)
	{
		Div = NULL;
		Mod = NULL;
		return;
	}
	Number *Mem = new Number;
	Mem->isPos = A->isPos;
	_Digit = A->Head;
	while (_Digit != NULL)
	{
		Digit *Temp = new Digit;
		Temp->Data = _Digit->Data;
		Mem->PushTail(Temp);
		_Digit = _Digit->Next;
	}
	Number MultiplyWith[10];
	Number *Ans = new Number;
	for (int i = 0; i <= 9; i++)
	{
		Temp = new Number;
		_Digit = new Digit;
		_Digit->Data = i;
		Temp->PushHead(_Digit);
		MultiplyWith[i] = *MultiplyN(B, Temp);
		delete Temp;
	}
	Number *Dividend = new Number;
	while (true)
	{
		_Digit = A->PopHead();
		if (_Digit == NULL)
		{
			break;
		}
		else
		{
			Dividend->PushTail(_Digit);
			for (int i = 9; i >= 0; i--)
			{
				Temp = new Number;
				*Temp = MultiplyWith[i];
				if (LargerThan(Dividend, Temp) != 0)
				{
					Dividend = MinusN(Dividend, Temp);
					_Digit->Data = i;
					Ans->PushTail(_Digit);
					break;
				}
			}
			while ((Dividend->Head != NULL) && (Dividend->Head->Data == 0))
			{
				Dividend->PopHead();
			}
		}
	}
	Finish(Ans);
	Finish(Dividend);
	Div = Ans;
	Mod = Dividend;
	A = Mem;
}



Number *PlusZ(Number *&A, Number *&B)
{
	if ((!A->isPos) && (!B->isPos))
	{
		Number *Ans = PlusN(A, B);
		Ans->isPos = false;
		return Ans;
	}
	if ((A->isPos) && (B->isPos))
	{
		return PlusN(A, B);
	}
	if ((A->isPos) && (!B->isPos))
	{
		return MinusN(A, B);
	}
	if ((!A->isPos) && (B->isPos))
	{
		return MinusN(B, A);
	}
	return NULL;
}

Number *MinusZ(Number *&A, Number *&B)
{
	if ((!A->isPos) && (!B->isPos))
	{
		return MinusN(B, A);
	}
	if ((A->isPos) && (B->isPos))
	{
		return MinusN(A, B);
	}
	if ((A->isPos) && (!B->isPos))
	{
		return PlusN(A, B);
	}
	if ((!A->isPos) && (B->isPos))
	{
		Number *Ans = PlusN(A, B);
		Ans->isPos = false;
		return Ans;
	}
	return NULL;
}

Number *MultiplyZ(Number *&A, Number *&B)
{
	Number *Ans = MultiplyN(A, B);
	if ((!A->isPos) && (!B->isPos))
	{
		return Ans;
	}
	if ((A->isPos) && (B->isPos))
	{
		return Ans;
	}
	if ((A->isPos) && (!B->isPos))
	{
		Ans->isPos = false;
		return Ans;
	}
	if ((!A->isPos) && (B->isPos))
	{
		Ans->isPos = false;
		return Ans;
	}
	return NULL;
}

Number *DivZ(Number *&A, Number *&B)
{
	Number *Div = new Number;
	Number *Mod = new Number;
	DivModN(A, B, Div, Mod);
	if ((!A->isPos) && (!B->isPos))
	{
		return Div;
	}
	if ((A->isPos) && (B->isPos))
	{
		return Div;
	}
	if ((A->isPos) && (!B->isPos))
	{
		Div->isPos = false;
		return Div;
	}
	if ((!A->isPos) && (B->isPos))
	{
		Div->isPos = false;
		return Div;
	}
	return NULL;
}

Number *ModZ(Number *&A, Number *&B)
{
	Number *Div = new Number;
	Number *Mod = new Number;
	DivModN(A, B, Div, Mod);
	if ((!A->isPos) && (!B->isPos))
	{
		return Mod;
	}
	if ((A->isPos) && (B->isPos))
	{
		return Mod;
	}
	if ((A->isPos) && (!B->isPos))
	{
		Mod->isPos = false;
		return Mod;
	}
	if ((!A->isPos) && (B->isPos))
	{
		Mod->isPos = false;
		return Mod;
	}
	return NULL;
}