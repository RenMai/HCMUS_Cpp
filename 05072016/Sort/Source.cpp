#include<iostream>
using namespace std;

void swap_int(int &a, int &b)
{
	int c;
		c = a;
		a = b;
	b = c;
}
void bbsort_int(int a[])
{
	for (int j = 0; j < 5; ++j)
	{
		for (int i = 0; i < 5-j; ++i)
		{
			if (a[i] < a[i + 1]) swap_int(a[i], a[i + 1]);
		}
	}
}
void sssort_int(int a[])
{
	for (int j = 0; j < 5; ++j)
	{
		int min = j;
		for (int i = j; i < 5; ++i)
		{
			if (a[min] > a[i]) min = i;
		}
		swap_int(a[min], a[j]);
	
	}
}
void print_array(int a[],int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i] << endl;
}
int main()
{
	int a[5] = { 5, 3, 2, 6, 1 };
	sssort_int(a);
	print_array(a, 5);
	
	return 0;
}