#pragma once;
#include <iostream>
#include <string>
using namespace std;

class staff 
{
private : 
	int salaries;
public : 
	staff();
	staff(int salary);
};

class ta : public staff
{
private : 
	float index;
	int hours;
public:
	ta();
	ta(int hrs, float indx, int sal);
	ta(int hrs, int sal);
	void inputH(ta &s);
};

class lecturer : public ta
{
private : 
	float index;
	int numpap, suppap;
public: 
	lecturer();
	lecturer(int hrs, float indx, int sal,int papnum, int papsup);
	lecturer(int papnum, int papsup);
	void input(ta &t);
};

class researcher : public lecturer
{
private : 
	float index;
	int project,prosal;
public : 
	researcher ();
	researcher (int pro, int prsal, int papsup, int papnum, float indx) ;
	void inputL(researcher & l);
};

class universities 
{
private: 
	string name;
	float index;
	ta t;
	lecturer le;
	researcher re;
public : 
	float tot;
	universities ();
	void input (universities &u);
};