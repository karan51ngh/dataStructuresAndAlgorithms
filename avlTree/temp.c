#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
long long area(triangle *p)
{
    int s = ((p->a) + (p->b) + p->c) / 2;
    int area = s * (s - p->a) * (s - p->b) * (s - p->c);
    return area;
}
void sort_by_area(triangle *p, int n)
{
    long long ar, min = 0;
    triangle *temp = (triangle *)malloc(sizeof(triangle));
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (area(p + i) < area(p + j))
            {
                temp->a = (p + i)->a;
                temp->b = (p + i)->b;
                temp->c = (p + i)->c;

                (p + i)->a = (p + j)->a;
                (p + i)->b = (p + j)->b;
                (p + i)->c = (p + j)->c;

                (p + j)->a = temp->a;
                (p + j)->b = temp->b;
                (p + j)->c = temp->c;
                continue;
            }
        }
    }
}

int main()
{
    system("cls");
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}
