#pragma once
#include "Header.h"

int main ()
{
	universities u[1000];
	for (int i=0; i<1000;++i)
	{
		u[i].input(u[i]);
	}
	cout <<u[999].tot;
	return 0;
}