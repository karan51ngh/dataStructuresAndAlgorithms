#include <iostream>
using namespace std;
signed main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int k = 9;
	int l = 0, r = 9;
	int m = (l + r) / 2;
	int flag = 0;
	while (1)
	{
		if (arr[m] != k)
		{
			flag = 1;
			break;
		}
		else if (k > arr[m])
		{
			l = m + 1;
			m = (l + r) / 2;
		}
		else if (k < arr[m])
		{
			r = m - 1;
			m = (l + r) / 2;
		}
	}
	if (flag)
		cout << "found\n";
	else
		cout << "not found\n";
}