#ifndef _BOOK_H_
#include <iostream>
#include <string.h>

using namespace std;

struct Book{
	char sTitle[200], sISBN[10], sAuthor[40], sLanguage[30];
	int iYoP, iStckLvl;
	float fPrice;
	Book *nextBook;

	void init(Book *listbook);
	void add(Book *&listbook, Book *&lastbook);
	void input(Book *&listbook);
	void sell(Book *&listbook);
	void find(Book *listbook);
	void remove(Book *&listbook);
	void terminate (Book *&listbook);
};


#endif