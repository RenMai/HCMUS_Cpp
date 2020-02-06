#include"Knight.h"

bool SolveKnightTour(int table[n][n], int col, int row, int count, int ColStep[], int RowStep[])
{
	int holdCol;
	int holdRow;
	if (count >= n*n)
	{
		return true;
	}
	for (int i = 0; i<8; i++)
	{
		holdCol = col + ColStep[i];
		holdRow = row + RowStep[i];
		if (isSafe(table, holdRow, holdCol))
		{
			table[holdRow][holdCol] = count;
			if (SolveKnightTour(table, holdCol, holdRow, count + 1, ColStep, RowStep))
			{
				return true;
			}
			else
			{
				table[holdRow][holdCol] = -1;
			}
		}

	}
	return false;
}
bool isSafe(int table[n][n], int row, int col)
{
	if (table[row][col] == -1 && row<n&&col<n&&row >= 0 && col >= 0)
	{
		return true;
	}
	return false;
}
void Display(int table[n][n])
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout.width(3);
			cout << table[i][j];
		}
		cout << endl;
	}
}
void SKnightTour()
{
	int ColStep[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int RowStep[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int table[n][n];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			table[i][j] = -1;
		}
	}
	table[0][7] = 0;
	if (SolveKnightTour(table, 7, 0, 1, ColStep, RowStep))
	{
		Display(table);
	}
}