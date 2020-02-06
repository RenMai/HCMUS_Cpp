#include"Queen.h"

bool Check(int index, int map[])
{
	int k = 1;
	for (int i = 1; i <= 8; i++)
	{
		bool check = true;
		for (int j = 0; j < index; j++)
		{
			if (i == map[j] || i == map[j] + index - j || i == map[j] - index + j)
			{
				check = false;
				break;
			}
			else
			{
				check = true;
			}
		}
		if (check == false)
		{
			continue;
		}
		else
		{
			map[index] = i;
			if (index == 7)
			{
				for (int m = 0; m < 8; m++)
				{
					cout << "[" << map[m] << "," << m << "] ";
				}
				cout << endl;
				return false;
			}
			if (!Check(index + 1, map))
			{
				continue;
			}
		}
	}
	return false;
}