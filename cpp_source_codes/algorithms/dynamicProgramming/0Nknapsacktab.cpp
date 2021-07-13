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
	int W;
	vi w;
	vi v;
	int n;
	int f()
	{
		int DP[n + 1][W + 1];

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= W; j++)
			{
				if (i == 0 || j == 0)
					DP[i][j] = 0;
				else if (w[i] > j)
					DP[i][j] = DP[i - 1][j];
				else
					DP[i][j] = max(v[i] + DP[i][j - w[i]], DP[i - 1][j]);
			}
		}
		// for (int i = 0; i <= n; i++)
		// {
		// 	for (int j = 0; j <= W; j++)
		// 		cout << DP[i][j] << " ";
		// 	cout << endl;
		// }
		return DP[n][W];
	}

	solution(vi w1, vi v1, int W1, int n1)
	{
		W = W1;
		w = w1;
		v = v1;
		n = n1;
		ans = f();
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
	vi w(n + 1, 0);
	vi v(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	solution s1(w, v, W, n);
	int ans = s1.ans;
	deb(ans);
}