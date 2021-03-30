#include <stdio.h>
#include <stdlib.h>

void bin(int);

int main()
{
    system("cls");
    int n;
    printf("enter n\n");
    scanf("%d", &n);
    bin(n);
    return 0;
}

void bin(int n)
{
    if (n == 1)
    {
        printf("%d", 1);
    }
    else
    {
        bin(n / 2);
        printf("%d", n % 2);
    }
}