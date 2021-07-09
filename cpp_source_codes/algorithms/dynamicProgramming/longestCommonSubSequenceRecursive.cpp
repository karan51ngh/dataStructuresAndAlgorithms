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
string trim(string s)
{
	string t;
	for (int i = 0; i < s.length() - 1; i++)
	{
		t = t + s[i];
	}
	return t;
}
bool lastSame(string s1, string s2)
{
	return (s1[s1.length() - 1] == s2[s2.length() - 1]);
}
int lcs(string s1, string s2)
{
	if (s1 == "" || s2 == "")
		return 0;
	if (lastSame(s1, s2))
	{
		return 1 + lcs(trim(s1), trim(s2));
	}
	else
	{
		return max(lcs(trim(s1), s2), lcs(s1, trim(s2)));
	}
}
void solved()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << lcs(s1, s2) << endl;
}