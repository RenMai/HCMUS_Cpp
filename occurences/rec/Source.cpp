#include<iostream>
using namespace std;

int choose(int n, int k)
{
	if (k == 0 || n == k) return(1);
	else return(choose(n - 1, k) + choose(n - 1, k - 1));
}
int main()
{
	//int a, b;
	//cin >> a >> b;
	//a = choose(a, b);
	//cout << a;
	//return 0;
	int a = 1;
	int b=0;
	cin >> a;
	if (a==true) cout << b;
	else cout << b + 1;
	cout << endl;

	//bool c;
	//cin >> c;
	//cout << c << endl;
	system("pause");
}