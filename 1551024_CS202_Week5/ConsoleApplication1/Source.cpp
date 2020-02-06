#include<iostream>
using namespace std;

int main()
{
	int n;
	int m = 0, S = 0;
	cin >> n;
	while (S <= n)
	{
		++m;
		S = S + m;
	}
	cout << m;
	return 0;
}