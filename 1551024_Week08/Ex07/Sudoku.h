#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include<iostream>
#include<fstream>

using namespace std;

int** InputMap();
bool Solve(int **map, int x, int y);
bool Check(int **map, int value, int x, int y);

#endif