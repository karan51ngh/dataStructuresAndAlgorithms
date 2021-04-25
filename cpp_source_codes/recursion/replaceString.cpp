// replace "pi" by "3.14"
#include <iostream>
using namespace std;
string replace(string);
signed main()
{
	string s1;
	cin >> s1;
	// int n = s1.size();
	cout << replace(s1);
	cout << endl;
}
string replace(string s1)
{
	if (s1.size() < 2)
	{
		return s1;
	}
	else
	{
		if (s1.substr(0, 2) == "pi")
		{
			return "3.14" + replace(s1.substr(2, s1.size()));
		}
		else
		{
			return s1[0] + replace(s1.substr(1, s1.size()));
		}
	}
}
