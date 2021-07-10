// MINIMAX problem

// there is an array of coins, play a coin game. a player can remove either the first or the last coin
// from the row and earn that value. determine the max value Player 1 wins, if he moves 1st.(both players play optimally)

// https://www.youtube.com/watch?v=g1uZPKKrm3U&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=179
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

// the opponent will try to make the optimal choice for himself

class solution
{
public:
	vi arr;
	int sol;
	int f(int i, int j)
	{
		// deb(i);
		// deb(j);
		// cout << endl;
		if (j == i + 1)
		{
			return max(arr[i], arr[j]);
		}
		else
		{

			int choice1 = arr[i] + min(f(i + 1, j - 1), f(i + 2, j));
			int choice2 = arr[j] + min(f(i, j - 2), f(i + 1, j - 1));
			// deb(choice1);
			// deb(choice2);
			// cout << endl;
			return max(choice1, choice2);
		}
	}
	solution(vi a)
	{
		arr = a;
		sol = f(0, a.size() - 1);
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
	int ans = s1.sol;
	deb(ans);
}
