#include "Header.h"

int main()
{
	shape *s;
	cout << "Enter the number of shape: ";
	int k;
	double bigP = 0.0, bigA = 0.0;
	cin >> k;
	s = new shape[k];
	for (int i = 0; i<k; ++i)
	{
		s[i].input(s[i]);
		if (s[i].paraS > bigP)
			bigP = s[i].paraS;
		if (s[i].areaS > bigA)
			bigA = s[i].areaS;
	}
	cout << "The largest para and largest area is: " << bigP << bigA << endl;
	return 0;
}