#include <stdio.h>
#include <stdlib.h>

void print(int);

int main()
{
    system("cls");
    int n;
    printf("enter n\n");
    scanf("%d", &n);
    print(n);
}

void print(int n)
{
    if (n == 0)
        return;
    else
    {
        print(n - 1);
        printf("%d ", n);
    }
}