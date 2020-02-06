// StudentID: 1551007
// Full name: Mai Thieu Nhan
// ExO3:

#include <iostream>
using namespace std;

void swap(int &x, int &y, int &z)
{
	int t = z;
	z = x;
	x = y;
	y = t;
}

int main()
{
	int x = 10, y = 20, z = 30;
	int *p, *q, *r;
	p = &x;
	q = &y;
	r = &z;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	cout << "p: " << p << endl;
	cout << "*p: " << *p << endl;
	cout << "q: " << q << endl;
	cout << "*q: " << *q << endl;
	cout << "r: " << r << endl;
	cout << "*r: " << *r << endl;
	cout << "Swapping values" << endl;
	swap(x, y, z);
	cout << endl;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	cout << "p: " << p << endl;
	cout << "*p: " << *p << endl;
	cout << "q: " << q << endl;
	cout << "*q: " << *q << endl;
	cout << "r: " << r << endl;
	cout << "*r: " << *r << endl;
	cout << endl;

	return 0;
}