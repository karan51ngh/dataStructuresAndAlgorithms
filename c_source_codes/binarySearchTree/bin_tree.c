//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
//structure of NODE
struct Node
{
    Node *lchild;
    char info;
    Node *rchild;
};
//functions
Node *getnode(char);
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);
//void level(Node *);
void display(Node *);
//program
int main()
{
    int c = 1, ch;
    system("cls");
    Node *root;
    //initialization of Tree
    root = getnode('A');
    root->lchild = getnode('B');
    root->rchild = getnode('C');
    root->lchild->lchild = getnode('D');
    root->lchild->rchild = getnode('E');
    root->rchild->lchild = getnode('F');
    //UI
    printf("welcome\n");
    while (c)
    {
        printf("******************************\n");
        printf("enter choice of traversal\n");
        printf(" 1.preorder\n");
        printf(" 2.inorder\n");
        printf(" 3.postorder\n");
        printf(" 4.level\n");
        printf(" 5.display the tree\n");
        printf("******************************\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            //level(root);
            break;
        case 5:
            display(root);
            break;
        }
        printf("Do You Wanna Continue? enter 1/0\n");
        scanf("%d", &c);
    }

    return 0;
}

Node *getnode(char c)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->info = c;
    node->lchild = NULL;
    node->rchild = NULL;
    return (node);
}

void preorder(Node *p) //NLR
{
    if (p == NULL)
    {
        return;
    }
    printf("%c ", p->info);
    preorder(p->lchild);
    preorder(p->rchild);
}

void inorder(Node *p) //LNR
{
    if (p == NULL)
    {
        return;
    }
    inorder(p->lchild);
    printf("%c ", p->info);
    inorder(p->rchild);
}

void postorder(Node *p) //LRN
{
    if (p == NULL)
    {
        return;
    }
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%c ", p->info);
}
/*void level(Node *p) //level Wise Printing
{
    insertqueue(p);
    whlle(!empty())
    {
        deleteq();
        if(p->lchild!=NULL)
        {
                insertqueue(p->lchild);
        }
        if(p->rchild!=NULL)
        {
                insertqueue(p->rchild);
        }
    }
}*/

void display(Node *p)
{
}