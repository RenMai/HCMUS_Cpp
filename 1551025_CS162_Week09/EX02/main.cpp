// ID : 1551023
// Name : Ho Sy Nguyen
// EX02
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void Split(string src , int parts)
{
	fstream filesrc;
	filesrc.open(src,ios::in|ios::binary);
	filesrc.seekg(0, filesrc.end);
    int length = filesrc.tellg();
	char x;
	int check = 0;
	int sum = 0;
	filesrc.seekg (0, filesrc.beg);
	for(int i = 0 ; i < parts ; i++)
	{
		fstream part;
		string output = src+".part";
		output.push_back((char)(i+'0'));
		cout<<output<<endl;
		part.open(output,ios::out|ios::binary);
		for(int j = i*length/parts; j < (i+1)*length/parts ; j++)
		{
			filesrc.read(&x,1);
			part.write(&x,1);
		}
		part.close();
	}
}
void Merge(string src , int parts ,string dest)
{
	char x;
	fstream out;
	out.open(dest,ios::out|ios::binary);
	for(int i = 0 ; i < parts ; i++)
	{
		fstream part;
		string output = src+".part";
		output.push_back((char)(i)+'0');
		part.open(output,ios::in|ios::binary);
		part.seekg(0, part.end);
		int length = part.tellg();
		part.seekg(0, part.beg);
		for(int i = 0 ; i < length ; i++)
		{
			part.read(&x,1);
			out.write(&x,1);
		}
		part.close();
	}
	out.close();
}

void main()
{
	string src;
	string dest;
	cout<<"Enter the name of the file : ";
	getline(cin,src);
	int i = 0;
	cout<<"Enter the number of parts : ";
	cin>>i;
	Split(src,i);
	cout<<"Enter the name of the merge file : ";
	cin.get();
	getline(cin,dest);
	Merge(src,i,dest);
}