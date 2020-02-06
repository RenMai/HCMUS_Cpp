
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
struct sub//subject
{
	string subject;
	sub* next;
	//input:subject need to be found
	//output: true->found, false->not found
	bool find(string);

	//delete all the list
	void del();
	//write down the list of subject down to file
	//A is ofstream to write
	void write_sub(ofstream& A);

};
//remove subject A from the list
//output:true-> succeed to remove A, else ->false.
bool remove(sub*& head, string A);
//add string A at the end of the list
void add_sub(sub*&head, string A);
//count the number of subject in the list 
int count_sub(sub*);



