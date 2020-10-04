//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
//structures
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};
//functions
Node *getNode(int);            //returns a new Node
Node *appendNode(Node *, int); //to append Node in the BST style
void inorder(Node *);          //inorder traversal
int heightCheck(Node *);       //checks weather the tree follows AVL property
Node *ubNode(Node *);          //returns the first unbalanced Node
int modTwo(int, int);          //checks weather the difference of the 2 heighs is less<=1
int height(Node *);            //reuturns height of a node
int greater(int, int);         //to get the larger height
Node *AVLinsert(Node *, int);  //for inserting in an AVL tree
//program
void main()
{
    system("cls");
    int r, ch, v;
    Node *root;
    printf("enter the root node\n");
    scanf("%d", &r);
    root = getNode(r);
    printf("do you want to add roots? enter 1/0");
    scanf("%d", &ch);
    while (ch)
    {
        printf("enter data\n");
        scanf("%d", &v);
        root = appendNode(root, v);
        printf("do you want to add roots? enter 1/0");
        scanf("%d", &ch);
    }
    inorder(root);
}
Node *getNode(int v)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = v;
    node->lchild = NULL;
    node->rchild = NULL;
    return (node);
}
void inorder(Node *t)
{
    if (t == NULL)
    {
        return;
    }
    inorder(t->lchild);
    printf("%d ", t->data);
    inorder(t->rchild);
}
int height(Node *t)
{
    if (t = NULL)
        return (0);
    else
    {
        return (1 + greater(height(t->lchild), height(t->rchild)));
    }
}
int greater(int x, int y)
{
    if (x > y)
        return (x);
    else
        return (y);
}
int modTwo(int x, int y)
{
    if ((x - y) < 2 || (x - y) > -2)
        return 1;
    else
        return 0;
}
int heightCheck(Node *t)
{
    if (t == NULL)
    {
        return 1; //because height checked
    }
    else
    {
        if (modTwo(height(t->lchild), height(t->rchild)) && (heightCheck(t->lchild) && heightCheck(t->rchild))) //forces the checking of all nodes
            return 1;
        else
            return 0;
    }
}
Node *appendNode(Node *t, int v)
{
    if (t == NULL)
    {
        t = getNode(v);
        return (t);
    }
    if (v > t->data)
    {
        t->rchild = appendNode(t->rchild, v);
    }
    if (v < t->data)
    {
        t->lchild = appendNode(t->lchild, v);
    }
    return (t);
}
Node *AVLinsert(Node *t, int v)
{
    t = appendNode(t, v);
    int b = heightCheck(t);
    int casee;
    if (b)
    {
        return (t);
    }
    else
    {
        Node *z = ubNode(t); //unbalanced node, grand parent Node of the Node x
        //x is the first Node whose grandparent is disturbed, y is the parent
        if (v < z->data && v < z->lchild->data)
        {
            Node *y = t->lchild;
            Node *x = y->lchild;
            casee = 1; //single rotation
            //LL
        }
        if (v > z->data && v > z->lchild->data)
        {
            Node *y = t->rchild;
            Node *x = y->rchild;
            casee = 2; //single rotation
            //RR
        }
        if (v < z->data && v > z->lchild->data)
        {
            Node *y = t->lchild;
            Node *x = y->rchild;
            casee = 3; //double rotation
            //LR
        }
        if (v > z->data && v < z->lchild->data)
        {
            Node *y = t->lchild;
            Node *x = y->lchild;
            casee = 4; //double rotation
            //RL
        }
    }
    if (casee == 1)
    {
    }
    if (casee == 2)
    {
        /* code */
    }
    if (casee == 3)
    {
        /* code */
    }
    if (casee == 4)
    {
        /* code */
    }
}