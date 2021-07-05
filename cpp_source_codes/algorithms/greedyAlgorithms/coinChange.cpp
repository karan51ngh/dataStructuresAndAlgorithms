// given an array of Denominations and a value X, You need to find the minimum number of coins required to make value X.
// NOTE: we have infinite supply of each coin
// input
// 10
// 1 2 5 10 20 50 100 200 500 2000
// 350
// output
// 3
// https://www.youtube.com/watch?v=IUQRh7SJwEM&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=145
#include <iostream>
#include <bits/stdc++.h>
#define int long
#define deb(x) cout << #x << " is " << x << endl
#define vi vector<int>
using namespace std;

signed main()
{
	int n;
	cin >> n;
	vi a(n, 0);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int x;
	cin >> x;
	sort(a.begin(), a.end(), greater<int>());
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		ans += x / a[i];
		x -= x / a[i] * a[i];
	}
	deb(ans);
	return 0;
}