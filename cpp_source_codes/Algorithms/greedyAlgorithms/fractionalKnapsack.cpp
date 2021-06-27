#include <iostream>
#include <vector>
using namespace std;
void swap(int *, int *);
int main()
{
    int wth;
    int n;
    cin >> n;
    cin >> wth;
    // vector<int> O, P, W;
    int PbW[n];
    int P[n];
    int W[n];
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }
    int Profit = 0;
    for (int i = 0; i < n; i++)
    {
        PbW[i] = float(P[i]) / W[i];
    }
    //sorting
    for (int i = 0; i < n - 1; i++)
    {
        int min = PbW[i];
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (PbW[j] < min)
            {
                min = PbW[j];
                index = j;
            }
        }
        swap(PbW + i, PbW + index);
        swap(W + i, W + index);
        swap(P + i, P + index);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (wth > W[i])
        {
            wth -= W[i];
            Profit += P[i];
        }
        else if (wth > 0 && wth < W[i])
        {

            Profit = Profit + P[i] * ((W[i] - wth) / W[i]);
            wth = 0;
        }
        else
        {
            break;
        }
    }
    cout << "the max profit is" << Profit << endl;
}
void swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}