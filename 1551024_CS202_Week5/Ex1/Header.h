#include <iostream>
#include <string>
using namespace std;

class staff
{
private:
	int salaries;
public:
	staff();
	staff(int salary);
};

class ta : public staff
{
private:
	float index;
	int hours;
public:
	ta();
	ta(int hrs, float indx, int sal);
	ta(int hrs, int sal);
	void inputH(ta &s);
};

class lect : public ta
{
private:
	float index;
	int numpap, suppap;
public:
	lect();
	lect(int hrs, float indx, int sal, int papnum, int papsup);
	lect(int papnum, int papsup);
	void input(ta &t);
};

class research : public lect
{
private:
	float index;
	int project, prosal;
public:
	research();
	research(int pro, int prsal, int papsup, int papnum, float indx);
	void inputL(research & l);
};

class universities
{
private:
	string name;
	float index;
	ta t;
	lect le;
	research re;
public:
	float tot;
	universities();
	void input(universities &u);
};