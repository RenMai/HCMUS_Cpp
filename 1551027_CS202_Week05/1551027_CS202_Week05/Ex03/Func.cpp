#include "Header.h"

OfStaff :: OfStaff()
{
	WorkDay=0;
	BaseOf=0;
	Allowance=0;
};


OfStaff :: OfStaff(int WD, float BO, float All)
{
	WorkDay=WD;
	BaseOf=BO;
	Allowance = All;
};

OfStaff :: OfStaff(int WD, float BO)
{
	WorkDay=WD;
	BaseOf=BO;
	Allowance = 300000;
};

float OfStaff:: Ofsal(bool Al)
{
	float sal;
	if (Al==true)
		sal=(this->WorkDay)*(this->BaseOf )+ 300000;
	else
		sal=(this->WorkDay)*(this->BaseOf);
	return sal;
};

ProStaff :: ProStaff()
{
	ProNum=0;
	ProPad=0.0;
};

ProStaff :: ProStaff(int PN, float PP)
{
	ProNum=PN;
	ProPad=PP;
};


float ProStaff :: Prosal ()
{
	return (this->ProNum) * (this->ProPad);
};

SaleStaff :: SaleStaff()
{
	SumPro=0;
	SoldPrice=0.0;
	Cost=0.0;
};


SaleStaff :: SaleStaff(int Sum, float Sold, float Co)
{
	SumPro=Sum;
	SoldPrice=Sold;
	Cost=Co;
};

float SaleStaff::Salesal()
{
	return 0.15*(this->SumPro)*(this->SoldPrice-this->Cost);
};

Company :: Company(string na,string e, string ad,time db)
{
	name = na;
	email=e;
	address=ad;
	dob=db;
};

Company Company :: input()
{
	string na,e, ad;
	time dob;
	cout << "name : " ;
	getline (cin,na);
	this->name=na;
	cout <<endl;
	cout << " email : " ;
	getline (cin,e);
	this->email=e;
	cout << endl;
	cout << " address : " ;
	getline (cin,ad);
	cout <<endl;
	this->address=ad;
	cout << " day of birth : day month year : ";
	cin >> dob.d>>dob.m>>dob.y;
	cout << endl;
	this->dob=dob;
	cout << " input type " ;
	int n;
	cin >> n;
	switch (n)
	{
	case 1 :
		{
			int WD;
			float BO,Al,sa;
			bool check;
			cout << " work day , Base Sal, Allow, sal " ;
			cin >> WD >> BO >> Al;
			cout <<" off days : ?! ";
			int c;
			cin >> c;
			if (c <3)
				check=true;
			else check = false;
			sa = this->o.Ofsal(check);
			OfStaff ole(WD,BO,Al);
			this->o=ole;
			this->sal=sal;
			this->type=n;
		}
	case 2:
		{
			int PN;
			float PP,sa;
			cout << " Proceduct Number , Product Paid " ;
			cin >> PN >> PP;
			ProStaff pole (PN,PP);
			this->p=pole;
			sa = pole.Prosal();
			this->sal=sa;
			this->type=n;
		}
	case 3:
		{
			int PS;
			float SP,Co;
			cout << " Sum of Product , Sold Price , Cost " ;
			cin >> PS>>SP>>Co;
			SaleStaff sale(PS,SP,Co);
			this->s=sale;
			float sa=sale.Salesal();
			this->sal=sa;
			this->type=n;
		}
	default :
		{
			cout<<" stupid shit wrong input" << endl;
		}
	}
	return *this;	
};

Company :: Company():OfStaff(),ProStaff(),SaleStaff()
{
	type=0;
	sal=0.0;
};

void Company ::sort(vector <Company> &C)
{
	for (int i=C.size(); i>0; --i)
	{
		for (int j =0, k=1;k<i; j++, k++)
		{
			if (C[j].sal > C[k].sal)
			{
				Company swap = C[j];
				C[j]=C[k];
				C[k]=swap;
			}
		}
	}
}
