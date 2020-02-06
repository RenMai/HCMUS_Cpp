#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <string.h>

using namespace std;

struct Book
{
public:
	char Title[201];
	char ISBN[11];
	char Author[41];
	char Language[31];
	int Year, Stock;
	float Price;
	Book* pNext=NULL;
};
void init(Book* &book);
void input(Book* &b);
void sell(Book* &b);
void find(Book* b);
void remove(Book* &b);
void removeall(Book* &b);

#endif