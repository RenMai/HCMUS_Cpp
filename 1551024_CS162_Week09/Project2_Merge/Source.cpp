#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool Merge(string sfn, int nop, string dfn)
{
	fstream src, des;
	string temp;
	char *data;
	int size;

	des.open(dfn, ios::binary | ios::out);

	for (int i = 1; i <= nop; i++)
	{
		src.open(sfn + "." + to_string(i), ios::binary | ios::in);
		if (!src.is_open())
		{
			return false;
		}
		src.seekg(0, ios::end);
		size = src.tellg();
		src.seekg(0, ios::beg);

		data = new char[size];

		src.read(data, size);
		des.write(data, size);

		src.close();
		delete[] data;
	}
	des.close();
	return true;
}

void main()
{
	string sfn, dfn;
	int nop;
	cout << "Enter the file name: ";
	getline(cin, sfn);
	cout << "Enter the number of parts: ";
	cin >> nop;
	cout << "Enter the destination file name: ";
	cin.get();
	getline(cin, dfn);
	if (!Merge(sfn, nop, dfn))
	{
		cout << "Error! Can't find your file. " << endl;
	}
	system("pause");
}
