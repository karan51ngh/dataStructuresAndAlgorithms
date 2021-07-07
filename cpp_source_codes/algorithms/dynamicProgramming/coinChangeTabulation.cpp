// given a set of coins and a value V, find the number of ways we can make change of V.
// example: S={1,2,3}, V=3, then possible solution is 3 -> {{3},{2,1},{1,1,1}}
// NOTE :{1,2} == {2,1} and therefore not seperate ways
// infinite supply of coins
// https://www.youtube.com/watch?v=GBBRjI_1LRI&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=174
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

void solved();

signed main()
{
	int T = 1;
	// cin >> T;
	while (T--)
		solved();
}
int coinChange(vi S, int V, int n)
{
	vector<vi> DP;
	vi temp(V + 1, 0);

	for (int i = 0; i <= n; i++)
		DP.push_back(temp);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= V; j++)
		{
			if (i == 0)
			{
				DP[i][j] = 0;
				DP[0][0] = 1;
			}

			else if (j < S[i])
			{
				DP[i][j] = DP[i - 1][j];
			}
			else
			{
				DP[i][j] = DP[i][j - S[i]] + DP[i - 1][j]; // NOT DP[i-1][j - S[i]] + DP[i - 1][j]; because we have infinite supply of coins(unlike 0/1 knapsack)
			}
		}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= V; j++)
			cout << DP[i][j] << " ";
		cout << endl;
	}
	return DP[n][V];
}
void solved()
{
	int n, V;
	cin >> n >> V;
	vi S(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> S[i];
	}
	sort(S.begin(), S.end());
	cout << coinChange(S, V, n) << endl;
}