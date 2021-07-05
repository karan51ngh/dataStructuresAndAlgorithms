// given n activities with start and finish times.
// select maximum number of activities that can be performed by a single person
// assuming that the person can work on a single activity at a time
// https://www.youtube.com/watch?v=DHr-Mn_vzs0&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=145
// sample input
// 3
// 10 20
// 12 15
// 20 30
// sample output
// 2
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl;
using namespace std;

signed main()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({start, end}); //trick
	}
	sort(v.begin(), v.end(), [&](vi &a, vi &b)
		 { return a[1] < b[1]; }); //sorting by ending times

	int take = 1;
	int end = v[0][1];

	for (int i = 1; i < n; i++)
	{
		if (v[i][0] >= end)
		{
			take++;
			end = v[i][1];
		}
	}
	deb(take);
}