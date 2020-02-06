#include"Function.h"
void BMPFile::ReadFromFile(string name)
{
	fstream file;
	file.open(name,ios::in|ios::binary);
	file.read((char*)&bfh,sizeof(bfh));
	file.read((char*)&dib,sizeof(dib));
	file.read((char*)&ct,sizeof(ct));
	int size = this->dib.width*this->dib.height*3;
	
	this->pa.Pixel = new char *[this->dib.width*3];
	
	for(int i = 0 ; i < this->dib.height*3 ; i++)
	{
		this->pa.Pixel[i] = new char [this->dib.height];
	}
	
	for(int i = 0 ; i < this->dib.height ; i++)
	{
		
		for(int j = 0 ; j < this->dib.width*3 ; j++)
		{
			file.read((char*)&this->pa.Pixel[j][i],sizeof(char));
		}
	}
	file.close();
}
void BMPFile::WriteRus(string name)
{
	fstream file;
	file.open(name,ios::out|ios::binary);
	this->dib.width=900;
	this->dib.height=600;
	this->dib.PAsize=dib.width*dib.height*3;
	file.write((char*)&bfh,sizeof(bfh));
	file.write((char*)&dib,sizeof(dib));
	file.write((char*)&ct,sizeof(ct));
	for(int i = 0 ; i < dib.height/3 ; i++)
	{
		for(int j = 0 ; j < dib.width*3 ; j+=3)
		{
			char red = 255;
			char blue = 0;
			char green = 0;
			file.write(&green,sizeof(green));
			file.write(&red,sizeof(red));
			file.write(&blue,sizeof(blue));
		}
	}
	for(int i = dib.height/3 ; i < dib.height/3*2 ; i++)
	{
		for(int j = 0 ; j < dib.width*3 ; j+=3)
		{
			char red = 0;
			char blue = 255;
			char green = 0;
			file.write(&green,sizeof(green));
			file.write(&red,sizeof(red));
			file.write(&blue,sizeof(blue));
		}
	}
	for(int i = dib.height/3*2 ; i < dib.height ; i++)
	{
		for(int j = 0 ; j < dib.width*3 ; j+=3)
		{
			char red = 255;
			char blue = 255;
			char green = 255;
			file.write(&green,sizeof(green));
			file.write(&red,sizeof(red));
			file.write(&blue,sizeof(blue));
		}
	}
	file.close();
}
void BMPFile::WriteUkr(string name)
{
	fstream file;
	file.open(name,ios::out|ios::binary);
	this->dib.width=900;
	this->dib.height=600;
	this->dib.PAsize=dib.width*dib.height*3;
	file.write((char*)&bfh,sizeof(bfh));
	file.write((char*)&dib,sizeof(dib));
	file.write((char*)&ct,sizeof(ct));
	for(int i = 0 ; i < dib.height/2 ; i++)
	{
		for(int j = 0 ; j < dib.width ; j++)
		{
			char red = 255;
			char blue = 0;
			char green = 255;
			file.write(&green,sizeof(green));
			file.write(&red,sizeof(red));
			file.write(&blue,sizeof(blue));
		}
	}
	for(int i = dib.height/2 ; i < dib.height ; i++)
	{
		for(int j = 0 ; j < dib.width ; j++)
		{
			char red = 0;
			char blue = 255;
			char green = 128;
			file.write(&green,sizeof(green));
			file.write(&red,sizeof(red));
			file.write(&blue,sizeof(blue));
		}
	}
	file.close();
}
