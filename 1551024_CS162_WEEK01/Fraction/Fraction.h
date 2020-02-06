#ifndef _FRACTION_H_
#define _FRACTION_H_

#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

struct Fraction{
	int num;
	int den;
};

void simplify(Fraction &x);
void input_fraction(Fraction &x);
void input_fraction_text(Fraction x[]);
void output_fraction(Fraction x);
void output_fraction_text(Fraction x);
Fraction add(Fraction a, Fraction b);
Fraction divide(Fraction a, Fraction b);
void update_num(Fraction &x);
void update_den(Fraction &x);
void get_num(Fraction x);
void get_den(Fraction x);
char compare(Fraction a, Fraction b);

#endif