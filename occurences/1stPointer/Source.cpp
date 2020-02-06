#include <iostream>
using namespace std;

struct Book
{
	char ID[16];
	char* sTitle, *sAuthor;
	float price;
	int stock, yearPublished;
	void input();
};
struct BookStore
{
	Book* listBook;
	int n;

	void input();
};

int main()
{

	return 0;
}