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
Node *getnode(int);
Node *enque(Node *, Node *, int);
Node *deque(Node *); //check the end case
void print(Node *);
//program
int main()
{
    system("cls");
    //declaration of variables
    int c, info, ch = 1;
    Node *front;
    Node *rear;
    front = getnode(NULL);
    rear = getnode(NULL);
    printf("Welcome!\n");
    while (1)
    {
        printf("*************************\n");
        printf("enter choice:\n");
        printf(" 1. enque\n");
        printf(" 2. deque\n");
        printf(" 3. print\n");
        printf("*************************\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("enter data\n");
            scanf("%d", &info);
            rear = enque(rear, front, info);
            break;
        case 2:
            front = deque(front);
            break;
        case 3:
            printf("the data in the queue is\n");
            print(front);
            break;
        }
        printf("wanna continue? press 1 or 0\n");
        scanf("%d", &ch);
        if (ch == 0)
        {
            printf("exiting!\n");
            break;
        }
    }
    return 0;
}
Node *getnode(int info)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = info;
    node->link = NULL;

    return (node);
}

Node *enque(Node *rear, Node *front, int info)
{
    if (front->data == NULL)
    {
        front->data = info;
        front->link = NULL;
        rear = front;
        return (rear);
    }

    Node *temp;
    temp = getnode(info);
    rear->link = temp;
    rear = temp;
    temp = NULL;
    return (rear);
}

void print(Node *front)
{
    Node *p;
    p = front;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
    return;
}

Node *deque(Node *front)
{
    Node *temp;
    temp = front;
    front = front->link;
    printf("dequing %d", temp->data);
    free(temp);
    return (front);
}