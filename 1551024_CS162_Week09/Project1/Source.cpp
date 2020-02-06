#include<fstream>
#include<iostream>
#include<string>

using namespace std;
void main()
{
	string sfn1,sfn2;
	cout << "Enter file name: ";
	getline(cin, sfn1);
	cout << "Enter file copy name: ";
	getline(cin, sfn2);
	fstream fin(sfn1, ios::binary | ios::in);
	fstream fout(sfn2, ios::binary | ios::out);

	char c;
	while (true) 
	{
		c = fin.get();
		if (fin.eof()) break;
		fout.put(c);
	}
	fin.close();
	fout.close();
}