//#include<iostream>
//#include<math.h>
//
//using namespace std;
//
//
//int main()
//{
//	int t = 1, k = 0;
//	cout << "Pls input number (0-stop):" << endl;
//	while (t != 0)
//	{
//		cin >> t;
//		k = k * 10 + t;
//	}
//	while (k != 0)
//	{
//		t = k % 10;
//		k = k / 10;
//		cout << t;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//

#include<iostream>
#include<math.h>
using namespace std;

int card(int k, int s[], int i);
int main()
{
	int k, i = 0;
	int s[5];
	s[0] = 500000;
	s[1] = 200000;
	s[2] = 100000;
	s[3] = 50000;
	s[4] = 20000;
	s[5] = 10000;
	cout << "Show me your money :3 : ";
	cin >> k;
	while (k % 10000 != 0)
	{
		--k;
	}
	cout << "I will sell you:" << k << " VND cards." << endl;
	card(k, s, i);
	return 0;
}
int card(int k, int s[], int i)
{
	int t;
	t = k / s[i];
	k = k - t*s[i];
	if (k > 0)
	{
		if (t > 0)
			cout << t << " card " << s[i] << " ";
		if (i < 5) return (card(k, s, i + 1));
	}
	else return 0;
}

