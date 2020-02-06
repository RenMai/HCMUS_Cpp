#include"Sudoku.h"

bool Check(int **map, int value, int x, int y)
{
	for (int i = 0; i < 9; i++)
	{
		if (map[x][i] == value)
		{
			return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (map[i][y] == value)
		{
			return false;
		}
	}
	x = x / 3 * 3 + 1;
	y = y / 3 * 3 + 1;
	for (int m = -1; m <= 1; m++)
	{
		for (int n = -1; n <= 1; n++)
		{
			if (map[x + m][y + n] == value)
			{
				return false;
			}
		}
	}
	return true;
}
bool Solve(int **map, int x, int y)
{
	if (x == 9)
	{
		x = 0;
		y++;
	}
	if (x == 0 && y == 9)
	{
		for (int a = 0; a < 9; a++)
		{
			for (int b = 0; b < 9; b++)
			{
				cout << map[a][b] << " ";
			}
			cout << endl;
		}
		ofstream fout;
		fout.open("Solution.txt");
		for (int a = 0; a < 9; a++)
		{
			for (int b = 0; b < 9; b++)
			{
				fout << map[a][b] << " ";
			}
			fout << endl;
		}
		fout.close();
	}
	if (map[x][y] != -1)
	{
		if (!Solve(map, x + 1, y))
		{
			return false;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (Check(map, i, x, y))
		{
			map[x][y] = i;
			if (!Solve(map, x + 1, y))
			{
				map[x][y] = -1;
			}
		}
	}
	return false;
}
int** InputMap()
{
	int **Map = new int *[9];
	for (int i = 0; i < 9; i++)
	{
		Map[i] = new int[9];
	}
	ifstream fin;
	fin.open("Sudoku.txt");
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			fin >> Map[x][y];
		}
	}
	fin.close();
	return Map;
}