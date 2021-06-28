#include <iostream>
// #include <vector>
using namespace std;
int max(int, int);
int knapsack(int, int, int, int, int *, int *);

int main()
{
    int W, n, i;
    cin >> W;
    cin >> n;
    int *w, *v;
    w = new int(n);
    v = new int(n);
    cout << "Enter weights";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    cout << "Enter profits";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int x = knapsack(W, 0, n, -1, w, v);
    cout << x << endl;
}
int knapsack(int W, int p, int n, int ctr, int *w, int *v)
{
    if (ctr == n || W < w[ctr])
    {
        return p;
    }
    else
    {
        return max(knapsack(W, p, n, ctr + 1, w, v), knapsack(W - w[ctr], p + v[ctr], n, ctr + 1, w, v));
    }
}
int max(int a, int b)
{
    return a >= b ? a : b;
}