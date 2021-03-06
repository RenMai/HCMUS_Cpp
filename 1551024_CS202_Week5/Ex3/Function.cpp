#include "Header.h"

OStaff::OStaff()
{
	WorkDay = 0;
	BaseOf = 0;
	Allowance = 0;
};


OStaff::OStaff(int WD, float BO, float All)
{
	WorkDay = WD;
	BaseOf = BO;
	Allowance = All;
};

OStaff::OStaff(int WD, float BO)
{
	WorkDay = WD;
	BaseOf = BO;
	Allowance = 300000;
};

float OStaff::Ofsal(bool Al)
{
	float sal;
	if (Al == true)
		sal = (this->WorkDay)*(this->BaseOf) + 300000;
	else
		sal = (this->WorkDay)*(this->BaseOf);
	return sal;
};

PStaff::PStaff()
{
	ProNum = 0;
	ProPad = 0.0;
};

PStaff::PStaff(int PN, float PP)
{
	ProNum = PN;
	ProPad = PP;
};


float PStaff::Prosal()
{
	return (this->ProNum) * (this->ProPad);
};

SStaff::SStaff()
{
	SumPro = 0;
	SoldPrice = 0.0;
	Cost = 0.0;
};


SStaff::SStaff(int Sum, float Sold, float Co)
{
	SumPro = Sum;
	SoldPrice = Sold;
	Cost = Co;
};

float SStaff::Salesal()
{
	return 0.15*(this->SumPro)*(this->SoldPrice - this->Cost);
};

Company::Company(string na, string e, string ad, time db)
{
	name = na;
	email = e;
	address = ad;
	dob = db;
};

Company Company::input()
{
	string na, e, ad;
	time dob;
	cout << "Enter name : ";
	getline(cin, na);
	this->name = na;
	cout << endl;
	cout << "Enter email : ";
	getline(cin, e);
	this->email = e;
	cout << endl;
	cout << "Enter the address : ";
	getline(cin, ad);
	cout << endl;
	this->address = ad;
	cout << "Enter day of birth (dd-mm-yy): ";
	cin >> dob.d >> dob.m >> dob.y;
	cout << endl;
	this->dob = dob;
	cout << "Enter type";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
	{
			  int WD;
			  float BO, Al, sa;
			  bool check;
			  cout << "Enter work day , base sal and allow sal ";
			  cin >> WD >> BO >> Al;
			  cout << "Enter off days : ";
			  int c;
			  cin >> c;
			  if (c <3)
				  check = true;
			  else check = false;
			  sa = this->o.Ofsal(check);
			  OStaff ole(WD, BO, Al);
			  this->o = ole;
			  this->sal = sal;
			  this->type = n;
	}
	case 2:
	{
			  int PN;
			  float PP, sa;
			  cout << "Enter Proceduct Number , Product Paid: ";
			  cin >> PN >> PP;
			  PStaff pole(PN, PP);
			  this->p = pole;
			  sa = pole.Prosal();
			  this->sal = sa;
			  this->type = n;
	}
	case 3:
	{
			  int PS;
			  float SP, Co;
			  cout << "Enter sum of product , sold price and cost ";
			  cin >> PS >> SP >> Co;
			  SStaff sale(PS, SP, Co);
			  this->s = sale;
			  float sa = sale.Salesal();
			  this->sal = sa;
			  this->type = n;
	}
	default:
	{
			   cout << "Input valid!" << endl;
	}
	}
	return *this;
};

Company::Company() :OStaff(), PStaff(), SStaff()
{
	type = 0;
	sal = 0.0;
};

void Company::sort(vector <Company> &C)
{
	for (int i = C.size(); i>0; --i)
	{
		for (int j = 0, k = 1; k<i; j++, k++)
		{
			if (C[j].sal > C[k].sal)
			{
				Company swap = C[j];
				C[j] = C[k];
				C[k] = swap;
			}
		}
	}
}
