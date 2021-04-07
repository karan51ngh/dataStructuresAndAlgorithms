// move all x to the end of the string
// axxbdacefxhix to abdcefhixxxxx
#include <iostream>
using namespace std;
string movex(string);
int main()
{
	string s1;
	cin >> s1;
	cout << movex(s1) << endl;
}

string movex(string s1)
{
	if (s1.size() == 1)
	{
		return s1;
	}
	else
	{
		if (s1[0] == 'x')
		{
			return movex(s1.substr(1, s1.size())) + "x";
		}
		else
		{
			return s1[0] + movex(s1.substr(1, s1.size()));
		}
	}
}