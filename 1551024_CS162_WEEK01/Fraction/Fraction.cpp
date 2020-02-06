#include"Fraction.h"

void simplify(Fraction &x)
{
	for (int i = x.den; i > 1; --i)
		{
			if (x.num % i == 0 && x.den%i == 0)
			{
				x.num = x.num / i;
				x.den = x.den / i;
			}
		}
}
void input_fraction(Fraction &x)
{
	cout << "Enter numerator: ";
	cin >> x.num;
	cout << "Enter denominator: ";
	cin >> x.den;
}
void input_fraction_text(Fraction x[])
{
	ifstream fin;
	fin.open("input.txt");
	int i = 0;
	fin >> x[i].num;
	fin >> x[i].den;
	fin.close();
}
void output_fraction(Fraction x)
{
	Fraction out;
	out.num = x.num;
	out.den = x.den;
	simplify(out);
	cout << out.num << "/" << out.den;
}
void output_fraction_text(Fraction x)
{
	ofstream fout;
	fout.open("output.txt");
	Fraction out;
	out.num = x.num;
	out.den = x.den;
	simplify(out);
	fout << out.num << "/" << out.den << endl;
}
Fraction add(Fraction a, Fraction b)
{
	Fraction add;
	add.num = a.num * b.den + b.num*a.den;
	add.den = a.den*b.den;
	simplify(add);
	return add;
}
Fraction divide(Fraction a, Fraction b)
{
	Fraction divide;
	divide.num = a.num*b.den;
	divide.den = b.num*a.den;
	simplify(divide);
	return divide;
}
void update_num(Fraction &x)
{
	int n;
	cout << "Enter the value of numerator you want to update: ";
	cin >> n;
	x.num = n;
}
void update_den(Fraction &x)
{
	int n;
	cout << "Enter the value of denominator you want to update: ";
	cin >> n;
	x.den = n;
}
void get_num(Fraction x)
{
	int n;
	n = x.num;
	cout << "The numerator is: " << n << endl;
}
void get_den(Fraction x)
{
	int n;
	n = x.den;
	cout << "The denominator is: " << n << endl;
}
char compare(Fraction a, Fraction b)
{
	char x;
	int n = a.num * b.den - b.num*a.den;
	if (n > 0) x = '>';
	else if (n < 0) x = '<';
	else x = '=';
	return x;
}