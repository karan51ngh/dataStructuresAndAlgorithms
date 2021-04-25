#include <iostream>
using namespace std;
string remDuplicates(string);
signed main()
{
	string s1;
	cin >> s1;
	cout << remDuplicates(s1);
	cout << endl;
}
string remDuplicates(string s1)
{
	if (s1.size() == 1)
	{
		return s1;
	}
	else
	{
		string temp = remDuplicates(s1.substr(1, s1.size()));
		if (s1[0] == temp[0])
		{
			return temp;
		}
		else
		{
			return s1[0] + temp;
		}
	}
}