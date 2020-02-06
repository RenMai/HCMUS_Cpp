#pragma once
#include "Number.h"

void Prepare(Number *&A, Number *&B);
void Finish(Number *&A);
int LargerThan(Number *&A, Number *&B);		//1: A>B , 0: A<B , -1: A=B

Number *PlusN(Number *&A, Number *&B);		//A+B	|	A>=0, B>=0
Number *MinusN(Number *&A, Number *&B);		//A-B	|	A>=0, B>=0

Number *PlusZ(Number *&A, Number *&B);
Number *MinusZ(Number *&A, Number *&B);

Number *MultiplyN(Number *&A, Number *&B);
Number *MultiplyZ(Number *&A, Number *&B);

void DivModN(Number *&A, Number *&B, Number *&Div, Number *&Mod);

Number *DivZ(Number *&A, Number *&B);
Number *ModZ(Number *&A, Number *&B);