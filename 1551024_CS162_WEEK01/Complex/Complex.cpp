#include"Complex.h"

void Input(Complex &x)
{
	cout<<"Enter the real value : ";
	cin>>x.real;
	cout<<"Enter the imaginary value : ";
	cin>>x.imaginary;
}
void Output(Complex x)
{
	cout<<x.real<<"+"<<x.imaginary<<"*i"<<endl;
}
Complex Add(Complex a , Complex b)
{
	Complex result;
	result.real=a.real+b.real;
	result.imaginary=a.imaginary+b.imaginary;
	return result;
}
Complex Subtract(Complex a , Complex b)
{
	Complex result;
	result.real=a.real-b.real;
	result.imaginary=a.imaginary-b.imaginary;
	return result;
}
float AbsoluteValue(Complex x)
{
	return sqrt(x.real*x.real+x.imaginary*x.imaginary);
}
bool EqualCheck(Complex a, Complex b)
{
	if(a.imaginary==b.imaginary&&a.real==b.real)
	{
		return true;
	}
	else
	{
		return false;
	}
}