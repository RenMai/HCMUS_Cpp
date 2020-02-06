// ID : 1551024
// Name : Mai Thieu Nhan
// EX02: Fraction
#include"Complex.h"

using namespace std;

void main()
{
	Complex main[2];
	cout<<"Enter the complex numbers : " <<endl;
	for(int i = 0 ; i <= 1 ; i++)
	{
		Input(main[i]);
		Output(main[i]);
	}
	cout<<"Add 2 complex numbers : ";
	Output(Add(main[0],main[1]));
	cout<<"Subtraction of complex numbers : ";
	Output(Subtract(main[0],main[1]));
	for(int i = 0 ; i <= 1 ; i++)
	{
		cout<<"Absolute value of ";
		Output(main[i]);
		cout<<" = "<<AbsoluteValue(main[i])<<endl;
	}
	if(EqualCheck(main[0],main[1]))
	{
		cout<<"EQUAL"<<endl;
	}
	else
	{
		cout<<"NOT EQUAL"<<endl;
	}
}