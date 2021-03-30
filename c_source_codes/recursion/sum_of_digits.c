#include <stdio.h>
#include <stdlib.h>

int sumd(int);

int main()
{
    system("cls");
    int i;
    printf("enter n\n");
    scanf("%d", &i);
    printf("the sum of digits is %d\n", sumd(i));
}
int sumd(int n)
{
    if ((n / 10) == 0)
    {
        return n;
    }
    else
    {
        return ((n % 10) + sumd(n / 10));
    }
}