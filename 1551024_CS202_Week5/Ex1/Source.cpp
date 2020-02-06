#include "Header.h"

int main()
{
	universities u[10000];
	for (int i = 0; i<10000; ++i)
	{
		u[i].input(u[i]);
	}
	cout << u[9999].tot;
	return 0;
}