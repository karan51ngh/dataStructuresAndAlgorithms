// given an array of items with their weigt and value.
// find the max value of items that can be stolen using a knapsack of capacity W.

// NOTE: you can choose INFINITE items of each type.

#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

void solved();

class solution
{
public:
	int ans;
	vi w;
	vi v;
	int n;
	vector<vi> memo;
	void memoInit()
	{
		vi temp(100, -1);
		for (int i = 0; i < 100; i++)
			memo.push_back(temp);
	}
	int f(int p, int W)
	{
		if (memo[p][W] != -1)
			return memo[p][W];

		int x;
		int max = -1;
		for (int i = 0; i < n; i++)
		{
			if (W < w[i])
				x = p;
			else
				x = f(p + v[i], W - w[i]);

			if (x > max)
				max = x;
		}
		memo[p][W] = max;
		return memo[p][W];
	}
	solution(vi w1, vi v1, int W1, int n1)
	{
		w = w1;
		v = v1;
		n = n1;
		memoInit();
		ans = f(0, W1);
	}
};

signed main()
{
	int T = 1;
	// cin >> T;
	while (T--)
		solved();
}

void solved()
{
	int W, n;
	cin >> n >> W;
	vi w(n);
	vi v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	solution s1(w, v, W, n);
	int ans = s1.ans;
	deb(ans);
}