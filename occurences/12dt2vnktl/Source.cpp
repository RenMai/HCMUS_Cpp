#include<iostream>
#include<math.h>

using namespace std;

void main()
{
	int n, k = 1, i = 1;
	float S = 0;
	cin >> n;
	while (k <= n)
	{
		S += i*1.0 / (2 * k);
		i *= -1;
		k += 1;
	}
	cout << S << endl;
	system("pause");
}