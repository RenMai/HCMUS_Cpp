#include <fstream>
#include <iostream>
#include "Sudoku.h"

using namespace std;

void main()
{
	int **Map = new int *[9];
	for (int i = 0; i < 9; i++)
	{
		Map[i] = new int[9];
	}
	Map = InputMap();
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (Map[x][y] == -1)
				cout << "  ";
			else
				cout << Map[x][y] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
	Solve(Map, 0, 0);

}