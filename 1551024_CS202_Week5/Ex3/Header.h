#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct time { int d, m, y; };

class Staff
{
protected: string name, email, address;
		   time dob;
};

class OStaff
{
private:
	int WorkDay;
	float BaseOf;
	float Allowance;
public:
	OStaff();
	OStaff(int WD, float BO, float All);
	OStaff(int WD, float BO);
	float Ofsal(bool Al);

};

class PStaff
{
private:
	int	ProNum;
	float ProPad;
public:
	PStaff();
	PStaff(int PN, float PP);
	float Prosal();
};

class SStaff : public Staff
{
private:
	int SumPro;
	float SoldPrice, Cost;
public:
	SStaff();
	SStaff(int Sum, float Sold, float Co);
	float Salesal();
};

class Company : public OStaff, PStaff, SStaff
{
private: OStaff o;
		 PStaff p;
		 SStaff s;
		 int type;
		 float sal;
public: float salC();
		Company();
		Company(string na, string e, string ad, time db);
		Company input();
		void sort(vector <Company> &C);
};