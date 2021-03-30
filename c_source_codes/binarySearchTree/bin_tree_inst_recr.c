//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
//structure of node
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};
//functions
Node *getnode(int);
void insert(Node *, int);
void inorder(Node *);
// program
int main()
{
    system("cls");
    int x, c;
    Node *root;
    printf("enter the values\n");
    scanf("%d", &x);
    root = getnode(x);
    printf("do you wanna continue? enter 1/0\n ");
    scanf("%d", &c);

    while (c)
    {
        scanf("%d", &x);
        insert(root, x);
        printf("do you wanna continue? enter 1/0\n ");
        scanf("%d", &c);
    }
    inorder(root);
    return 0;
}

Node *getnode(int info)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = info;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void insert(Node *p, int x)
{
    if (x > p->data)
    {
        if (p->rchild == NULL)
        {
            p->rchild = getnode(x); //so that you can use void insteadt of updating the list everytime
            return;
        }
        insert(p->rchild, x);
    }
    if (x < p->data)
    {
        if (p->lchild == NULL)
        {
            p->lchild = getnode(x);
            return;
        }
        insert(p->lchild, x);
    }
}

void inorder(Node *p)
{
    if (p == NULL)
        return;
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
    return;
}