//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
//structures
struct Node
{
    int data;
    Node *link;
};
//functions
Node *push(Node *, int);
Node *pop(Node *);
void print(Node *);
//program
int main()
{
    system("cls");
    //declaration of variables
    int c, info, ch = 1;
    Node *top;
    //initializing the stack
    top = (Node *)malloc(sizeof(Node));
    top->data = NULL;
    top->link = NULL;

    printf("Welcome!\n");
    while (1)
    {
        printf("*************************\n");
        printf("enter choice:\n");
        printf(" 1. push\n");
        printf(" 2. pop\n");
        printf(" 3. print\n");
        printf("*************************\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("enter data\n");
            scanf("%d", &info);
            top = push(top, info);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            print(top);
            break;
        }
        printf("wanna continue? press 1 or 0\n");
        scanf("%d", &ch);
        if (ch == 0)
        {
            printf("exiting!");
            break;
        }
    }
}

Node *push(Node *top, int v) //returns a pointer to Node(Node *)
{

    Node *temp; //creating temp
    temp = (Node *)malloc(sizeof(Node));
    temp->data = v;
    temp->link = NULL;

    if (top->data == NULL) //in case of empty stack
    {
        top->data = v;
    }

    else //in case stack has some stuff
    {
        temp->link = top;
        top = temp;
    }
    return (top); //returning the address stored in top,  hence working.
}

Node *pop(Node *top)
{
    Node *temp;
    temp = top;
    if (top->data == NULL)
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("popped element is %d", top->data);
        top = top->link;
        free(temp);
    }
    return (top);
}

void print(Node *head)
{
    Node *ptr;
    ptr = head;
    printf("%d ", ptr->data);
    do
    {
        ptr = ptr->link;
        printf("%d ", ptr->data);
    } while (ptr->link != NULL);
    printf("\n");
    return;
}