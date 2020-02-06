#include "Header.h"

int main ()
{
	Company tmp;
	vector <Company> Y;int n;
	do
	{
		cout << " 1 to continue to input "<<endl;
		cin >> n;
		if (n!=1)
			break;
		else
		{
			tmp.input();
			Y.push_back(tmp);
		}
	}
	while (n==1);
	tmp.sort(Y);
	return 0;
}