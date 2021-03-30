//INCOMPLETE
#include <stdio.h>
#include <stdlib.h>

int bin(int);

int main()
{
    system("cls");
    int n, b;
    printf("enter n\n");
    scanf("%d", &n);
    b = bin(n);
    printf("the binary is %d", b);
    return 0;
}

int bin(int n)
{
    int sum = 0, x;
    if (n == 1)
    {
        return 1;
    }
    else
    {
        x = bin(n / 2);
        //printf("%d", n % 2);
    }
}
