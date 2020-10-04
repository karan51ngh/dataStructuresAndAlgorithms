#include <stdio.h>
#include <stdlib.h>

int sum(int);

int main()
{
    system("cls");

    int n;
    printf("enter n\n");
    scanf("%d", &n);
    printf("%d", sum(n));
    return 0;
}
int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n + sum(n - 1));
    }
}