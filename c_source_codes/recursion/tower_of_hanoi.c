#include <stdio.h>
#include <stdlib.h>
void toh(int, char, char, char);
void main()
{
    system("cls");
    int n;
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
}
void toh(int n, char from, char using, char to)
{
    if (n == 1)
    {
        printf("move %d from %c to %c\n", n, from, to);
        return;
    }
    else
    {
        toh(n - 1, from, to, using);
        printf("move %d from %c to %c\n", n, from, to);
        toh(n - 1, using, from, to);
    }
}