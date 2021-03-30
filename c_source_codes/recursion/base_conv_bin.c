#include <stdio.h>
#include <stdlib.h>

void bin(int);

int main()
{
    system("cls");
    int n;
    printf("enter n\n");
    scanf("%d", &n);
    //printf("the binary form of ur integer is %d",bin(n));
    bin(n);
    return 0;
}

void bin(int n)
{
    int sum = 0;
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