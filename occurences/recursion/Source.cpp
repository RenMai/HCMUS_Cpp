#include<iostream>
#include<math.h>
using namespace std;

int card(int k, int s[], int i);
int main()
{
	int k;
	int s[6];
	s[1] = 500000;
	s[2] = 200000;
	s[3] = 100000;
	s[4] = 50000;
	s[5] = 20000;
	s[6] = 10000;
	cout << "Show me your money :3 : ";
	cin >> k;
	while (k % 10000 != 0)
	{
		--k;
	}
	cout << "I will sell you:" << k << " VND cards." << endl;
	card(k, s, 1);
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
			cout << t << " card " << s[i] <<" ";
		if (i < 5) return (card(k, s, i + 1));
	}
	else return 0;
}