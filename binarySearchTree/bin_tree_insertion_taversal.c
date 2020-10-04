#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
Node *getNode(int);
void insert(Node *, int);

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};
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
    while (c)
    {
        printf("enter the type of traversal\n");
        printf("1.preorder traversal\n");
        printf("2.inorder traversal\n");
        printf("3.postorder traversal\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("the preorder traversal is\n");
            preorder(root);
            printf("\n");
            break;
        case 2:
            printf("the preorder traversal is\n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("the preorder traversal is\n");
            postorder(root);
            printf("\n");
            break;
        }
        printf("enter 1/0 to traverse with a different order\n");
        scanf("%d", &c);
    }
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
void preorder(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
}
void inorder(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
}
void postorder(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    preorder(p->lchild);
    preorder(p->rchild);
    printf("%d ", p->data);
}