// check if an array is sorted or not
#include <iostream>
#include <limits.h>
using namespace std;
int checkSort(int *, int, int, int);
signed main()
{
	int arr[] = {1, 3, 5, 8, 10};
	int n = 5;
	int arr2[] = {1, 3, 2, 9, 5, 8, 10};
	int n2 = 7;
	cout << checkSort(arr, -1, INT_MIN, n);
	cout << endl;
	cout << checkSort(arr2, -1, INT_MIN, n2);
	cout << endl;
}
int checkSort(int *arr, int i, int v, int n)
{
	if (n == 1)
	{
		if (arr[i + 1] >= v)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (arr[i + 1] >= v)
		{
			return checkSort(arr, i + 1, arr[i + 1], n - 1);
		}
		else
		{
			return 0;
		}
	}
}