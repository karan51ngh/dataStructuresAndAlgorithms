//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
//structure
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};
//functions
Node *getnode(int);
void inorder(Node *);
int bin_ser(Node *, int);
//program
int main()
{
    system("cls");
    Node *root;
    int key;
    //binary search tree structur design
    root = getnode(25);
    root->lchild = getnode(20);
    root->lchild->lchild = getnode(15);
    root->lchild->rchild = getnode(21);
    root->lchild->rchild->rchild = getnode(24);
    root->lchild->lchild->lchild = getnode(10);
    root->lchild->lchild->rchild = getnode(17);
    root->rchild = getnode(30);
    root->rchild->lchild = getnode(27);
    root->rchild->rchild = getnode(35);
    root->rchild->rchild->rchild = getnode(36);

    printf("the inorder represenation is :\n");
    inorder(root);
    printf("\n\n");
    printf("enter the key\n");
    scanf("%d", &key);

    if (bin_ser(root, key))
    {
        printf("key found\n");
    }
    else
    {
        printf("key not found\n");
    }
    return 0;
}

Node *getnode(int info)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = info;
    node->lchild = NULL;
    node->rchild = NULL;
    return (node);
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

int bin_ser(Node *ptr, int k)
{
    while (1)
    {
        if (ptr == NULL)
            return 0;
        if (ptr->data == k)
            return 1;

        if (ptr->data < k)
            ptr = ptr->rchild;
        else
            ptr = ptr->lchild;
    }
}