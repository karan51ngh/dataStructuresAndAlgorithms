// given an array of integers, where each element represents
// the max # of steps that can be made forward from the element.
// 0 implies element cant move forward.
// return minimum # of jumps to reach the end of the array from the start.

// DP approach is O(n^2), greedy approach is O(n)
// https://www.youtube.com/watch?v=0cjO51vAY44&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=179

#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

class solution
{
public:
	int ans;
	int end;
	vi arr;
	int mj(int start, int cost)
	{
		// deb(start);
		// deb(arr[start]);
		// deb(arr[end]);
		// cout << endl;
		if (start == end)
		{
			return cost;
		}
		if (start >= end)
		{
			return INT_MAX;
		}
		if (arr[start] == 0)
		{
			return INT_MAX;
		}

		else
		{
			int minn = INT_MAX;
			for (int i = 1; i <= arr[start]; i++)
			{
				int x = mj(start + i, cost + 1);
				if (x < minn)
					minn = x;
			}
			return minn;
		}
	}
	solution(vi a)
	{
		arr = a;
		end = a.size() - 1;
		ans = mj(0, 0);
	}
};

void solved();
signed main()
{
	int T = 1;
	// cin >> T;
	while (T--)
		solved();
}
void solved()
{
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	solution s1(arr);
	int ans = s1.ans;
	deb(ans);
}