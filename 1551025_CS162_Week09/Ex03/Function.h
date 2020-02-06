#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

#pragma pack(1)
struct BitmapFileHeader
{
	char BM[2];
	unsigned int size;
	unsigned int reserved;
	unsigned int offset;
};
#pragma pack(1)
struct DIBHeader
{
	unsigned int size;
	unsigned int width;
	unsigned int height;
	short colorplane;
	short colordepth;
	int compress;
	int PAsize;
	unsigned int horizon;
	unsigned int vertical;
	int palette;
	int important;
};
#pragma pack(1)
struct ColorTable
{
	int colorformat;
};
#pragma pack(1)
struct PixelArray
{
	char **Pixel;
};
#pragma pack(1)
struct BMPFile
{
	BitmapFileHeader bfh;
	DIBHeader dib;
	ColorTable ct;
	PixelArray pa;
	void InputFile(string name);
	void ReadFromFile(string name);
	void WriteRus(string name);
	void WriteUkr(string name);
	void WriteMN(int m , int n);
};

#endif


