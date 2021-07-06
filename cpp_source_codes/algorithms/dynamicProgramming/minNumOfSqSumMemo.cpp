// minimum # of squares required to give number n
// https://www.youtube.com/watch?v=EoMxK6zh9wU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=174
#include <iostream>
#include <limits.h>
#include <bits/stdc++.h>
#define int long
#define vi vector<int>
#define deb(x) cout << #x << " is " << x << endl
using namespace std;

class solution
{
public:
	int sol;
	vi memo;
	void init_memo(int n)
	{
		for (int i = 0; i <= n; i++)
			memo.push_back(0);
	}
	int f(int x)
	{

		if (x == 0)
			return 0;
		else
		{
			if (memo[x] != 0)
				return memo[x];
			else
			{
				int min = INT_MAX;
				for (int i = 1; i <= sqrt(x); i++)
				{
					int y = f(x - (i * i)) + 1; //1 is coz we're using 1
					if (y < min)
						min = y;
				}
				memo[x] = min;
				return memo[x];
			}
		}
	}
	solution(int n)
	{
		init_memo(n);
		sol = f(n);
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
	solution S1(n);
	int ans=S1.sol;

	deb(ans);
}
