#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool Split(string sfn, int nop)
{
	fstream src, des;
	char *data;
	int size;

	src.open(sfn, ios::binary | ios::in);
	if (!src.is_open())
	{
		return false;
	}

	src.seekg(0, ios::end);
	size = src.tellg();
	src.seekg(0, ios::beg);

	data = new char[size];
	src.read(data, size);
	src.close();

	int j = 0;
	for (int i = 1; i <= nop; i++)
	{
		des.open((sfn + "." + to_string(i)), ios::binary | ios::out);
		for (; j < size; j++)
		{
			des.write(&data[j], 1);
			if ((j >= (size / nop)*i) && (i < nop))
			{
				j++;
				break;
			}
		}
		des.close();
	}
	delete[] data;
	return true;
}

void main()
{
	string sfn;
	int nop;
	cout << "Enter file name: ";
	getline(cin, sfn);
	cout << "Enter number of Parts: ";
	cin >> nop;
	if (!Split(sfn, nop))
	{
		cout << "Error! Can't find your file." << endl;
	}
	system("pause");
}