// heaps are implemented using arrays(sequential representation) coz heaps are complete trees.
//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
//functions
int *restoreUp(int *, int);
int *restoredown(int *, int);
//program
int main()
{
    system("cls");
    int i, n, ch;
    printf("enter the number of elements to be heapified\n");
    scanf("%d", &n);
    int arr[100];
    int *heap = arr;
    printf("enter the elements\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the approach to be used\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Top Down approach\n");
        for (i = 2; i <= n; i++)
        {
            heap = restoreUp(heap, i);
        }
        break;
    case 2:
        printf("Bottom Up approach\n");
        for (i = (n / 2); i >= 1; i--)
        {
            heap = restoredown(heap, i);
        }
        break;
    }

    for (i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
}
int *restoreUp(int *heap, int k) // working
{
    int *p1, *p2, temp;

    while (heap[k] > heap[k / 2])
    {
        p2 = &heap[k];
        p1 = &heap[k / 2];
        temp = *p2;
        *p2 = *p1;
        *p1 = temp;
        k = k / 2;
    }
    return (heap);
}
int *restoredown(int *heap, int k) //not working
{
    printf("entered resdown\n");
    int *p1, *p2, *p3, temp;

    while (heap[k] < heap[2 * k] || heap[k] < heap[2 * k + 1])
    {
        printf("entered while loop\n");
        p1 = &heap[k];
        p2 = &heap[2 * k];
        p3 = &heap[2 * k + 1];

        if (heap[2 * k] > heap[2 * k + 1])
        {
            printf("entered if\n");
            temp = *p2;
            *p2 = *p1;
            *p1 = temp;
            k = (2 * k);
        }
        else
        {
            printf("entered else\n");
            temp = *p3;
            *p3 = *p1;
            *p1 = temp;
            k = (2 * k + 1);
        }
    }

    printf("returning \n");
    return (heap);
}