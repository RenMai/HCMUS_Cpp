#include<stdio.h>
#include<Windows.h>
#include<fstream>
#include<iostream>

using namespace std;

void draw(int i, int j, int r, int g, int b) 
{
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);
	SetPixel(hdc, j, i, RGB(r, g, b));
	ReleaseDC(console, hdc);
}

void main()
{
	int width, height;
	fstream file;
	file.open("bitmap.bmp", ios::in | ios::binary);
	file.seekg(18, ios::beg);
	file.read((char *)&width, 4);
	file.seekg(22, ios::beg);
	file.read((char *)&height, 4);
	file.seekg(54, ios::beg);
	for (int i = height; i >= 1; --i)
	{
		for (int j = 1; j <= width; ++j)
		{
			char red, blue, green;
			file.read((char *)&blue, 1);
			file.read((char *)&green, 1);
			file.read((char *)&red, 1);
			draw(i, j, red, green,blue);
		}
	}
	cin.get();
}