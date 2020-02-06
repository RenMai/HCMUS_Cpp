#include "Header.h"

int main()
{
	shape *s;
	cout << " input number of shape : ";
	int n;
	double bigP=0.0,bigA=0.0;
	cin >> n;
	s= new shape [n];
	for (int i =0 ; i<n;++i)
	{
		s[i].input(s[i]);
		if (s[i].paraS > bigP)
			bigP=s[i].paraS;
		if (s[i].areaS > bigA)
			bigA=s[i].areaS;
	}
	cout << " biggest para and biggest area " << bigP << bigA;
	return 0;
}