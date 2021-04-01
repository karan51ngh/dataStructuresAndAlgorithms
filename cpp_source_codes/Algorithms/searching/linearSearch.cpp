#include <iostream>
using namespace std;
signed main()
{
	int arr[] = {6, 5, 7, 4, 8, 3, 9, 2, 0, 1};
	int k = 9;
	int flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (k == arr[i])
		{
			flag = 1;
		}
	}
	if (flag)
		cout << "found\n";
	else
		cout << "not found\n";
}