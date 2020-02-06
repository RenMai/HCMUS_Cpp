// ID : 1551023
// Name : Ho Sy Nguyen
// EX01 
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void Copy(string src , string dest)
{
	fstream filesrc;
	filesrc.open(src,ios::in|ios::binary);
	fstream filedest;
	filedest.open(dest,ios::out|ios::binary);
	char x;
	while(!filesrc.eof())
	{
		filesrc.read(&x,1);
		filedest.write(&x,1);
	}
	cout<<"Done"<<endl;
}

void main()
{
	string src;
	string dest;
	cout<<"Enter the name of the file : ";
	getline(cin,src);
	cout<<"Enter the name of the copy : ";
	getline(cin,dest);
	Copy(src,dest);
}