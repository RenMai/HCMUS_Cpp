#pragma once
#define n 8

#include<iostream>
#include<math.h>

using namespace std;

bool SolveKnightTour(int table[n][n], int col, int row, int count, int ColStep[], int RowStep[]);
bool isSafe(int table[n][n], int row, int col);
void Display(int table[n][n]);
void SKnightTour();