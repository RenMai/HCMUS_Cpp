#ifndef _APCS_H_
#define _APCS_H_

#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

struct Apcs
{
	char ID[8];
	char Name[31];
	char Address[51];
	int Day;
	int Month;
	int Year;
	int Grade;
};
bool checkleap(Apcs x);

bool checkdob(Apcs x);
void input_dob(Apcs &x);
void input(Apcs &x);
void input_text(Apcs &x);
void output(Apcs x);
void output_text(Apcs x);
char classify(Apcs x);

#endif
