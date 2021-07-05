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
	vi memo;
	int sol;
	solution(int n)
	{
		// cout << "hello in constructor\n";
		memo_init(n);
		sol = fibo(n);
	}

	void memo_init(int n)
	{
		// cout << "hello in memo_init\n";
		for (int i = 0; i <= n; i++)
		{
			memo.push_back(0);
			if (n >= 2)
				memo[2] = 1;
		}
	}
	int fibo(int n)
	{
		// cout << "hello in fibo\n";

		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		else
		{
			if (memo[n] != 0)
				return memo[n];
			else
			{
				memo[n] = fibo(n - 1) + fibo(n - 2);
				return memo[n];
			}
		}
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
