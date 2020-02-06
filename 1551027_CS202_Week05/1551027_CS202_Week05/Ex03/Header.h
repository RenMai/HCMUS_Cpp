#pragma once;
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct time { int d, m, y; };

class Staff
{
protected: string name ,email, address;
		  time dob;
};

class OfStaff 
{
private : 
		int WorkDay;
		float BaseOf;
		float Allowance;
public : 
	OfStaff();
	OfStaff(int WD, float BO, float All);
	OfStaff(int WD, float BO);
	float Ofsal(bool Al);
	
};

class ProStaff 
{
private : 
	int	ProNum;
	float ProPad;
public :
	ProStaff();
	ProStaff(int PN, float PP);
	float Prosal();
};

class SaleStaff : public Staff
{
private : 
	int SumPro;
	float SoldPrice,Cost;
public : 
	SaleStaff () ;
	SaleStaff (int Sum, float Sold,float Co);
	float Salesal();
};

class Company : public OfStaff,ProStaff,SaleStaff
{
private : OfStaff o;
		  ProStaff p;
		  SaleStaff s;
		  int type;
		  float sal;
public : float salC();
		 Company();
		 Company(string na,string e, string ad,time db);
		 Company input();
		 void sort(vector <Company> &C);
};