#ifndef _APCS_H_
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

struct APCS
{
	int ID;
	int ncourse;
	char name[100];
	int courid[];
	char courname;
};

void input_student(struct APCS);
void input_course(int &n);

#endif