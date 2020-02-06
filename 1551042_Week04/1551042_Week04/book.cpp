#include "book.h"

void Book::init(Book *listbook)
{
	Book *tmp = listbook;
	while (tmp != NULL){
		listbook = listbook->nextBook;
		delete tmp;
		tmp = listbook;
	}
}

void Book::add(Book *&listbook, Book *&lastbook)
{
	if (listbook == NULL)
	{
		listbook = new Book;
		listbook->nextBook = NULL;
		input(listbook);
		lastbook = listbook;
	}
	else
	{
		Book *tmpbook = new Book;
		input(tmpbook);
		// av
		Book *cur = listbook;
		while (cur!=NULL){
			if ((strcmp((cur->sTitle),(tmpbook->sTitle))==0)&&(strcmp((cur->sISBN),(tmpbook->sISBN))==0)&&(strcmp((cur->sAuthor),(tmpbook->sAuthor))==0)&&(strcmp((cur->sLanguage),(tmpbook->sLanguage))==0)&&(cur->fPrice==tmpbook->fPrice)&&(cur->iYoP==tmpbook->iYoP))
			{
				cur->iStckLvl += tmpbook->iStckLvl;
				return;
			}
			else
			{
				cur = cur->nextBook;
			}
		}
		// new one
		lastbook->nextBook = tmpbook;
		lastbook = lastbook->nextBook;
		lastbook ->nextBook = NULL;
	}
}

void Book::input(Book *&listbook){
	cin.ignore(1000,'\n');
	cout<<"Input Title: ";
	cin.getline(listbook->sTitle,201,'\n');
	cout<<"Input ISBN: ";
	cin.getline(listbook->sISBN,11,'\n');
	cout<<"Input Author: ";
	cin.getline(listbook->sAuthor,41,'\n');
	cout<<"Input Language: ";
	cin.getline(listbook->sLanguage,31,'\n');
	cout<<"Input Publish year: ";
	cin>>listbook->iYoP;
	cout<<"Input Price: ";
	cin>>listbook->fPrice;
	cout<<"Input Stock level: ";
	cin>>listbook->iStckLvl;
}

void Book::sell(Book *&listbook){
	char sell[10];
	int count = 0;
	Book *cur = listbook;
	cout<<"Insert a desired ISBN: ";
	cin.ignore(1000,'\n');
	cin.getline(sell,11,'\n');
	while (cur != NULL)
	{
		if (strcmp(sell,cur->sISBN)==0)
		{
			cout<<"Name: "<<cur->sTitle<<endl;
			cout<<"Price: "<<cur->fPrice<<endl;
			count++;
			if (cur->iStckLvl>0)
			{
				cur->iStckLvl--;
			}
			else
			{
				cout<<"OUT OF STOCK"<<endl;
			}
			return;
		}
		else
		{
			cur = cur->nextBook;
		}
	}
	if (count == 0)
	{
		cout<<"No such book"<<endl;
		return;
	}
}

void Book::find(Book *listbook)
{
	char find[10];
	int count = 0;
	Book *cur = listbook;
	cout<<"Insert ISBN: ";
	cin.ignore(1000,'\n');
	cin.getline(find,11,'\n');
	while (cur != NULL)
	{
		if (strstr(cur->sTitle,find)!=NULL)
		{
			count++;
			cout<<"ISBN: "<<cur->sISBN<<endl;
			cout<<"Title: "<<cur->sTitle<<endl;
			cur = cur->nextBook;
		}
		else
		{
			cur = cur->nextBook;
		}
	}
	if (count == 0)
	{
		cout<<"No results found for you search.\n";
	}
}

void Book::remove(Book *&listbook)
{
	int threshold = 0;
	cout<<"Insert threshold k: ";
	cin>>threshold;
	if (listbook != NULL)
	{
		if (listbook->iStckLvl < threshold)
		{
			Book *tmp = listbook;
			listbook = listbook->nextBook;
			delete tmp;
		}
	}
	Book *prev = listbook, *cur = listbook->nextBook;
	while (cur!=NULL)
	{
		if (listbook->iStckLvl < threshold)
		{
			Book *tmp = cur;
			if (cur->nextBook == NULL)
			{
				delete tmp;
			}
			else
			{
				cur = cur->nextBook;
				delete tmp;
			}
		}
		else
		{
			prev = cur;
			cur = cur->nextBook;
		}
	}
}

void Book::terminate(Book *&listbook)
{
	while (listbook != NULL)
	{
		Book *tmp = listbook;
		listbook = listbook->nextBook;
		delete tmp;
	}
}