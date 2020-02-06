#include<iostream>
#include<stdio.h>

using namespace std;
//
//void main()
//{
//	int n = 1000;
//	for (int i = 1; i <= n; i++)
//	{
//		int k = i;
//		int s = 0;
//		while (k != 0)
//		{
//			s = s*10 + k % 10;
//			k = k / 10;
//		}
//		if (s == i) cout << s << endl;
//	}
//	system("pause");
//}
#include<conio.h>
#include<math.h>
double tinh(long y)
{
	int q = 1, w;
	double tong = 0;
	long y1 = y;
	while (y1>10)
	{
		y1 = y1 / 10;
		q++;
	}
	while (y>0)
	{
		w = y % 10;
		tong = tong + pow(w, q);
		y = y / 10;
	}
	return tong;
}
void main()
{
	for (long j = 1; j <= 1000000; j++)
	{
		if (j == tinh(j))
			cout << j << ", ";
	}
	system("pause");
}