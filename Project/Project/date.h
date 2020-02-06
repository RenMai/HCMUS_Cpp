#pragma once
struct date
{
	int dd, mm, yy;//day,month,year
	//input month and year
	//return the max day of that month
	int day_of_month();
	//input yy
	//leap year return 1, else return 0
	bool leap();
	//input dd,mm,yy
	//valid->return true, else return false
	bool check();
};