#include <stdio.h>
#include <stdlib.h>

int npow(int, int);

int main()
{
    system("cls");
    int n, p;
    printf("enter the num\n");
    scanf("%d", &n);
    printf("enter the pow\n");
    scanf("%d", &p);
    printf("the power of number is %d", npow(n, p));
    return 0;
}
int npow(int n, int p)
{
    if (p == 1)
    {
        return n;
    }
    else
    {
        return (n * npow(n, p - 1));
    }
}