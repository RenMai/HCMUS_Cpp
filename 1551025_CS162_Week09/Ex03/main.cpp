// ID : 1551023
// Name : Ho Sy Nguyen
// EX03
#include"Function.h"
void main()
{
	BMPFile bmp;
	bmp.ReadFromFile("ABC.bmp");
	if(strcmp(bmp.bfh.BM,"BM"))
	{
		cout<<"This is a bmp file"<<endl;
	}
	else
	{
		cout<<"This is not a bmp file"<<endl;
	}
	cout<<"Size : "<<bmp.bfh.size<<endl;
	cout<<"Width : "<<bmp.dib.width<<endl;
	cout<<"Height : "<<bmp.dib.height<<endl;
	cout<<"Color Depth : "<<bmp.dib.colordepth<<endl;
	cout<<"Horizon : "<<bmp.dib.horizon<<endl;
	cout<<"Vertical : "<<bmp.dib.vertical<<endl;
	bmp.WriteRus("Rus.bmp");
	bmp.WriteUkr("Urk.bmp");
} 