// given 2 strings return the length of the longest common sub sequence
// https://www.youtube.com/watch?v=Esx-TxF5PSo&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=176

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
int lcs(string s1, string s2)
{
	int n = s1.length();
	int m = s2.length();
	int table[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || j == 0)
			{
				table[i][j] = 0;
				continue;
			}
			if (s1[i] != s2[j])
			{
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
				continue;
			}
			if (s1[i] == s2[j])
			{
				table[i][j] = 1 + table[i - 1][j - 1];
				continue;
			}
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		cout << table[i][j] << " ";
	// 	cout << endl;
	// }
	return table[n - 1][m - 1];
}
void solved()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;

	cout << lcs(s1, s2) << endl;
}