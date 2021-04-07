#include <iostream>
using namespace std;
void Permutation(string, int);
string swap(string, int, int);
signed main()
{
	string x;
	cin >> x;
	cout << endl;
	Permutation(x, -1);
}
void Permutation(string s1, int i)
{
	if (i == s1.size() - 1)
	{
		cout << s1 << endl;
		return;
	}
	else
	{
		i = i + 1;
		for (int p = i; p <= s1.size() - 1; p++)
		{
			s1 = swap(s1, i, p);
			Permutation(s1, i);
			s1 = swap(s1, i, p);
		}
	}
}
string swap(string s1, int i, int j)
{
	char t = s1[i];
	s1[i] = s1[j];
	s1[j] = t;
	return s1;
}