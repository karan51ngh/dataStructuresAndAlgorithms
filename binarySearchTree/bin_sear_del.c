//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
//structure of NODE
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
void del(Node *, int);
// program
int main()
{
    system("cls");
    int x, c, y;
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
    printf("printing the keys in inorder fashion\n");
    inorder(root);
    printf("enter the element to be deleted\n");
    scanf("%d", &y);
    del(root, y);
    printf("printing the keys in inorder fashion\n");
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
            p->rchild = getnode(x);
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

void del(Node *p, int x)
{
    Node *par; //parent p will point to the node
    par = p;
    //find node- to write the case for node not found

    while (1)
    {
        if (x == par->lchild->data || x == par->rchild->data)
        {
            if (x > par->data)
                p = p->rchild;
            if (x < par->data)
                p = p->lchild;
            break;
        }
        if (x > par->data)
        {
            par = par->rchild;
        }
        if (x < p->data)
        {
            par = par->lchild;
        }
    }
    // deleting node
    if (p->lchild == NULL && p->rchild == NULL) //caseA: leaf Node
    {
        if (p == par->rchild)
            par->rchild = NULL;
        if (p == par->lchild)
            par->lchild = NULL;
        return;
    }
    if (p->lchild == NULL || p->rchild == NULL) //caseB: Node has 1 child.......optimization of memory required(complete deletion)
    {
        if (p == par->rchild)
        {
            if (p->lchild == NULL) //case: p has only right child
            {
                par->rchild->data = p->rchild->data;
                p->rchild = NULL;
            }
            if (p->rchild == NULL) //case: p has only left child
            {
                par->rchild->data = p->lchild->data;
                p->lchild = NULL;
            }

            if (p == par->lchild)
            {
                if (p->lchild == NULL) //case: p has only right child
                {
                    par->lchild->data = p->rchild->data;
                    p->rchild = NULL;
                }
                if (p->rchild == NULL) //case: p has only left child
                {
                    par->lchild->data = p->lchild->data;
                    p->lchild = NULL;
                }
            }

            return;
        }
        if (p->lchild != NULL && p->rchild != NULL) //caseC: Node has 2 children
        {
            // find the inorder successor of the node
            Node *ptr = p;
            while (ptr->lchild != NULL) //ptr points to node
            {
                ptr = ptr->lchild;
            }
            if (p == par->rchild)
            {
                par->rchild->data = ptr->lchild->data; //copying data
            }
        }
    }