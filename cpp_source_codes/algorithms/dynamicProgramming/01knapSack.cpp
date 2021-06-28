#include <iostream>
#include <vector>
using namespace std;
int max(int, int);
int knapsack(int *, int *, int, int);
int main()
{
    int w, n;
    cin >> w >> n;
    int W[n + 1];
    int V[n + 1];
    int arr[w + 1][n + 1];
    W[0] = 0;
    V[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> W[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> V[i];
    }
    cout << knapsack(W, V, w, n);
}
int max(int a, int b)
{
    return a >= b ? a : b;
}
int knapsack(int *W, int *V, int w, int n)
{
    int K[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (W[i] > j)
            {
                K[i][j] = K[i - 1][j];
            }
            else
            {
                K[i][j] = max(V[i] + K[i - 1][j - W[i]], K[i - 1][j]);
            }
        }
    }
    return K[n][w];
}