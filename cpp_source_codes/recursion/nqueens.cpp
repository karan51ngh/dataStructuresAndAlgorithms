#include <iostream>
using namespace std;
int nqueen(int, int);
void setSol(int);
void setOccu(int);
void Occupy(int, int, int);
void UnOccupy(int, int, int);
bool checkPos(int **, int, int);
void print(int **, int);
int **sol;
int **occu;
signed main()
{
	int n;
	cin >> n;
	setSol(n);
	setOccu(n);
	int temp = nqueen(0, n);
	print(sol, n);
	cout << endl;
}
int nqueen(int r, int n)
{
	if (r == n - 1)
	{
		for (int f = 0; f < n; f++)
		{
			if (!checkPos(occu, r, f))
			{
				Occupy(r, f, n);
				sol[r][f] = 1;
				return 1;
			}
		}
		return 0;
	}
	else
	{
		for (int f = 0; f < n; f++) //for all the files in a rank
		{
			if (!checkPos(occu, r, f))
			{
				Occupy(r, f, n);
				int temp;
				temp = nqueen(r + 1, n);
				if (temp == 0)
				{
					UnOccupy(r, f, n);
					continue;
				}
				else
				{
					sol[r][f] = 1;
					return 1;
				}
			}
		}

		return 0; //no space in the rank
	}
}
void setSol(int n)
{
	sol = new int *[n];
	for (int i = 0; i < n; i++)
	{
		sol[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			sol[i][j] = 0;
		}
	}
}
void setOccu(int n)
{
	occu = new int *[n];
	for (int i = 0; i < n; i++)
	{
		occu[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			occu[i][j] = 0;
		}
	}
}

bool checkPos(int **mtx, int r, int f)
{
	if (mtx[r][f] == 0)
		return 0;
	else
		return 1;
}

void Occupy(int r, int f, int n) //working
{
	for (int i = r + 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)

		{
			if (j == f)
			{
				occu[i][j] += 1;
			}
			if (i - j == r - f)
			{
				occu[i][j] += 1;
			}
			if (i + j == r + f)
			{
				occu[i][j] += 1;
			}
		}
	}
}

void UnOccupy(int r, int f, int n) //working
{
	for (int i = r + 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)

		{
			if (j == f)
			{
				occu[i][j] -= 1;
			}
			if (i - j == r - f)
			{
				occu[i][j] -= 1;
			}
			if (i + j == r + f)
			{
				occu[i][j] -= 1;
			}
		}
	}
}

void print(int **mtx, int n) //working
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mtx[i][j];
		}
		cout << endl;
	}
}