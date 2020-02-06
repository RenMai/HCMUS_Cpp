#include<iostream>
#include<math.h>

using namespace std;


int main()
{
	int t = 1 , k = 0;
	cout << "Pls input number (0-stop):" << endl;  
	while (t != 0)
	{
		cin >> t;
		k = k * 10 + t;
	}
	while (k != 0)
	{
		t = k % 10;
		k = k / 10;
		cout << t;
	}
	cout << endl;
	system("pause");
	return 0;
}

