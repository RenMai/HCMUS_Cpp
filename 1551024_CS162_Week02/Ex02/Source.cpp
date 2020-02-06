// StudentID: 1551007
// Full name: Mai Thieu Nhan
// ExO2:

#include <iostream>
#include <iomanip>
using namespace std;

void hex(int x)
{
	cout << hex << x << endl;
}

int main()
{
	int x = 2, y = 8;
	int *p, *q;
	p = &x;
	q = &y;

	cout << "x value: " << x << endl;
	cout << "x address: " << &x << endl;
	cout << "y value: " << y << endl;
	cout << "y address: " << &y << endl;
	cout << "p address: " << p << endl;
	cout << "p value: " << *p << endl;
	cout << "q address: " << q << endl;
	cout << "q value: " << *q << endl;
	cout << "p address (not its content): " << p << endl;
	cout << "q address (not its content): " << q << endl;
	cout << endl;

	hex(x);
	hex(y);

	return 0;
}