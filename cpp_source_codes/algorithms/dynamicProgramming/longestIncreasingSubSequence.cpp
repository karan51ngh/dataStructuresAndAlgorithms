// you are given an array
// Find the length of the longest increasing sub-sequence
// sub array:continuous block
// sub sequence:part, in order(not continuous)

// https://www.youtube.com/watch?v=okgM58Tv9jQ&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=176
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
int longesstIncreasingSS(int n, vi seq)
{
	vi table(n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (seq[i] > seq[j])
				table[i] = max(table[j] + 1, table[i]);
		}
	}
	int max = 1;
	for (auto itr = table.begin(); itr < table.end(); itr++)
	{
		if (max < (*itr))
			max = (*itr);
	}
	return max;
}
void solved()
{
	int n;
	cin >> n;
	vi seq(n);
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	cout << longesstIncreasingSS(n, seq) << endl;
}