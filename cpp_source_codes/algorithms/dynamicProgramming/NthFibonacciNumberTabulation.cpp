// Time Complexity without DP: O(2^n)
// Time Complexity with DP: O(n)

// https://www.youtube.com/watch?v=YkBch12jNE0&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=172
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

class solution
{
public:
	vi tab;
	int sol;
	solution(int n)
	{
		sol = fibo(n);
	}

	int fibo(int n)
	{
		tab.push_back(0);
		tab.push_back(0);
		tab.push_back(1);
		if (n > 2)
		{
			for (int i = 3; i <= n; i++)
			{
				int x;
				x = tab[i - 1] + tab[i - 2];
				tab.push_back(x);
			}
		}
		return tab[n];
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
	solution s1(n);
	deb(s1.sol);
}