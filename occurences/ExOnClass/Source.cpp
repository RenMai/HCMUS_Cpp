#include<iostream>
using namespace std;
void main()
{
	char str1[100];
	char str2[100];
	int k = 0;
	cin.getline(str1, 100, '\n');
	cin.getline(str2, 100, '\n');
	for (int i = 0; i < strlen(str1); ++i)
	{
		if (str1[i] == str2[0])
		{
			for (int j = 0; j < strlen(str2); ++j)
			{
				if (str1[i + j] != str2[j]) break;
				if (j == strlen(str2) - 1) ++k;
			}
		}
	}
	cout << k << endl;
}