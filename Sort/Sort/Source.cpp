#include<iostream>

using namespace std;
#define S 9

void swapint(int *arr, int pos1, int pos2)
{
	int a = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = a;

}

int Par(int *arr, int low, int high)
{
	swapint(arr, low, (low + high) / 2);
	int pivot = arr[low];
	int smallest = low;
	int i = low + 1; 
	while (i <= high)
	{
		if (arr[i] < pivot)
		{
			++smallest;
			swapint(arr, i, smallest);
		}
		++i;
	}
	swapint(arr, low, smallest);
	return smallest;
}
void ReQuickSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pospivot = Par(arr, low, high);
		ReQuickSort(arr, low, pospivot - 1);
		ReQuickSort(arr, pospivot + 1, high);
	}
}
void QuickSort(int *arr)
{
	ReQuickSort(arr, 0, S-1);

}
void main()
{
	int a[S] = { 5, 6, 7, 8, 9, 1, 2, 3, 1 };
	for (int i = 0; i < S; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	QuickSort(a);
	for (int i = 0; i < S; ++i)
	{
		cout << a[i] << " ";
	}
}