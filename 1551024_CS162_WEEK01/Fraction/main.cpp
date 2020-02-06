// ID : 1551024
// Name : Mai Thieu Nhan
// EX01: Fraction
#include"Fraction.h"

using namespace std;

int main()
{
	char input;
	float a = 0;
	cout << "Enter a to input the fraction by keyboard; Enter b to input the fraction by text : " << endl;
	cin >> input;
	Fraction fraction[2];
	if (input == 'a')
	{
		input_fraction(fraction[0]);
	}
	else if (input == 'b') input_fraction_text(fraction);
	else
	{
		cout << "Your input is valid. Please try again." << endl;
		return 0;
	}
	cout << "Your fraction: "; output_fraction(fraction[0]); cout << endl;
	output_fraction_text(fraction[0]);
	cout << "Enter the second fraction." << endl;
	input_fraction(fraction[1]);
	simplify(fraction[1]);
	output_fraction(fraction[0]); cout << "+"; output_fraction(fraction[1]); cout << "="; output_fraction(add(fraction[0], fraction[1]));
	cout << endl;
	output_fraction(fraction[0]); cout << "/"; output_fraction(fraction[1]); cout << "="; output_fraction(divide(fraction[0], fraction[1]));
	cout << endl;
	cout << endl;
	update_num(fraction[0]);
	update_den(fraction[0]);
	get_num(fraction[0]);
	get_den(fraction[0]);
	output_fraction(fraction[0]); cout<<compare(fraction[0], fraction[1]); output_fraction(fraction[1]);
	cout << endl;
	return 0;
}