#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node
{
    int data;
    Node *link;
};
void push(Node **, int);
void pop(Node **);
Node *getNode(int);
void print(Node **);
void main()
{
    system("cls");
    Node **top;
    int n, i, j;
    top = (Node **)malloc(sizeof(Node *));
    *top = NULL;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &j);
        push(top, j);
    }
    print(top);
}
Node *getNode(int v)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = v;
    node->link = NULL;
    return (node);
}
void push(Node **top, int v)
{
    if ((*top) == NULL)
    {
        *top = getNode(v);
        return;
    }
    else
    {
        Node *t;
        t = *top;
        Node *newNode;
        newNode = getNode(v);
        *top = newNode;
        newNode->link = t;
        return;
    }
}
void print(Node **top)
{
    Node *t;
    t = *top;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->link;
    }
    return;
}