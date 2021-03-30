#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};
Node *getNode(int);
void insert(Node *, int);
int height(Node *);
int greater(int, int);
void main()
{
    system("cls");
    int bool = 1, v, ch, c;
    Node *root;
    printf("enter the data\n");
    scanf("%d", &v);
    root = getNode(v);
    printf("enter 1/0 to continue\n");
    scanf("%d", &bool);
    while (bool)
    {
        printf("enter the data\n");
        scanf("%d", &v);
        insert(root, v);
        printf("enter 1/0 to continue\n");
        scanf("%d", &bool);
    }
    printf("the height is %d\n", height(root));
}
Node *getNode(int v)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->lchild = NULL;
    node->data = v;
    node->rchild = NULL;
    return (node);
}
void insert(Node *p, int v)
{
    if (v > p->data)
    {
        if (p->rchild == NULL)
        {
            p->rchild = getNode(v);
            return;
        }
        insert(p->rchild, v);
    }
    if (v < p->data)
    {
        if (p->lchild == NULL)
        {
            p->lchild = getNode(v);
            return;
        }
        insert(p->lchild, v);
    }
}
int height(Node *h)
{
    if (h == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + greater(height(h->lchild), height(h->rchild)));
    }
}
int greater(int x, int y)
{
    if (x >= y)
        return (x);
    else
        return (y);
}