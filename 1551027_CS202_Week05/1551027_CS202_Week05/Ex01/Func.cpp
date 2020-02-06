#include "Header.h"

void universities::input(universities &u)
{
	getline(cin,u.name);
	cout << "type ( 1: TA, 2: Lecturer, 3:Researcher "<<endl;
	int n;
	cin >> n;
	if (n==1){
		int hrs, sal; 
		float index;
		cin >>hrs>>sal>>index;
		ta fu (hrs,index,sal);
		u.t = fu;
		u.tot=u.tot+0.8 * hrs *sal;
	}
	else if (n==2){
		int hrs,sal;
		float index;
		int papnum, suppap;
		cin >>hrs>>sal>>index>>papnum>>suppap;
		lecturer fu (hrs, index, sal, papnum, suppap);
		u.le = fu;
		u.tot=u.tot + 1.2*hrs*sal +papnum*suppap;
	}
	else{
		int pro, prosal, papsup, papnum;
		float index;
		cin >>pro>>prosal>>papsup>>papnum>>index;
		researcher fu (pro,prosal,papsup,papnum,index);
		u.re=fu;
		u.tot = pro*prosal*1.1 + papsup*papnum + u.tot;
	}
	
};


universities::universities()
{
	name = "Nguyen Ngoc Long Quan";
	index = 1.0;
	tot=0.0;
};

staff :: staff()
{
	universities::universities();
	salaries = 100;
};

ta :: ta()
{
	staff();
	hours=8;
};

staff :: staff(int salary)
{
	salaries=salary;
};

ta :: ta (int hrs, float indx,int sal) : staff(sal)
{
	hours = hrs;
	index=indx;
};

ta :: ta(int hrs, int sal):	staff(sal)
{
	hours=hrs;
};

void ta:: inputH(ta &s)
{
	cin >> s.hours;
};

lecturer :: lecturer ()
{
	ta();
	numpap=0;
	suppap=0;
};

void lecturer :: input(ta &t)
{
	cin >> numpap>> suppap;
};

lecturer :: lecturer(int hrs, float indx, int sal,int papnum, int papsup):ta( hrs,  sal)
{
	ta( hrs,  sal);
	index=indx;
	numpap=papnum;
	suppap=papsup;
};

lecturer :: lecturer(int papnum, int papsup)
{
	numpap= papnum;
	suppap=papnum;

};

researcher :: researcher()
{
	lecturer();
	project = 0;
	prosal =0;
};

researcher :: researcher (int pro, int prsal, int papsup, int papnum, float indx) :lecturer( papnum,  papsup)
{
	index = indx;
	project = pro;
	prosal = prsal;
};

void researcher ::inputL(researcher &l)
{
	cin >> l.project>>l.prosal;
};


