#include <iostream>
using namespace std;
int *merge(int *, int *, int, int);
int *mergeSort(int *, int);
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr = mergeSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int *merge(int *a1, int *a2, int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    int *a = new int[n1 + n2];
    while (i < n1 && j < n2)
    {

        if (a1[i] < a2[j])
            a[k++] = a1[i++];
        else
            a[k++] = a2[j++];
    }

    while (i < n1)
        a[k++] = a1[i++];

    while (j < n2)
        a[k++] = a2[j++];
    return a;
}
int *mergeSort(int *a, int n)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        int *a1 = new int[n / 2];
        int *a2 = new int[n - n / 2];

        for (int i = 0; i < n / 2; i++)
        {
            a1[i] = a[i];
        }
        int j = 0;
        for (int i = n / 2; i < n; i++)
        {
            a2[j] = a[i];
            j++;
        }

        a1 = mergeSort(a1, n / 2);
        a2 = mergeSort(a2, n - n / 2);
        return merge(a1, a2, n / 2, n - n / 2);
    }
}