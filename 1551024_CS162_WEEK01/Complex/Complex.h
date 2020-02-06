#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <math.h>
#include <iostream>

using namespace std;

struct Complex{
	float real;
	float imaginary;
};
void Input(Complex &x);
void Output(Complex x);
Complex Add(Complex a , Complex b);
Complex Subtract(Complex a , Complex b);
float AbsoluteValue(Complex x);
bool EqualCheck(Complex a, Complex b);
#endif