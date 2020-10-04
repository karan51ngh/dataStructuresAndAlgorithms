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
void append(Node *, int);
void print(Node *);
void pop(Node *);
void insert(Node *, int, int);
void reverse(Node *);
//program
int main()
{
    system("cls");
    //declaration of variables
    int c, info, ch = 1, n;
    Node *head;
    //initializing the list
    head = (Node *)malloc(sizeof(Node));
    head->data = NULL;
    head->link = NULL;

    printf("Welcome!\n");
    while (1)
    {
        printf("*************************\n");
        printf("enter choice:\n");
        printf(" 1. append data\n");                   //working
        printf(" 2. pop\n");                           // NOT WORKING
        printf(" 3. print the linked list\n");         //working
        printf(" 4. add element after the index n\n"); //working
        printf(" 5. reverse the list\n");              //NOT WORKING
        printf("*************************\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("enter data\n");
            scanf("%d", &info);
            append(head, info);
            break;
        case 2:
            pop(head);
            break;
        case 3:
            printf("the linked list is:\n");
            print(head);
            break;
        case 4:
            printf("enter data\n");
            scanf("%d", &info);
            printf("enter index\n");
            scanf("%d", &n);
            insert(head, info, n);
            break;
        case 5:
            reverse(head);
        }
        printf("wanna continue? press 1 or 0\n");
        scanf("%d", &ch);
        if (ch == 0)
        {
            printf("exiting!");
            break;
        }
    }

    return 0;
}

void append(Node *head, int v)
{
    Node *temp;
    Node *ptr;
    temp = (Node *)malloc(sizeof(Node));
    if (head->data == NULL)
    {
        head->data = v;
    }
    else if (head->link == NULL)
    {
        temp->data = v;
        temp->link = NULL;
        head->link = temp;
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        temp->data = v;
        temp->link = NULL;
        ptr->link = temp;
    }
    return;
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

void pop(Node *head) //needs tweaking
{
    Node *p;
    p = head;
    while (p->link != NULL)
    {
        p = p->link;
    }
    printf("the element just popped is %d", p->data);
    free(p); //need to point the 2nd last node to NULL
    return;
}

void insert(Node *head, int v, int n)
{
    int idx = 0;
    Node *temp;
    Node *ptr;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = v;
    ptr = head;
    while (idx < n)
    {
        ptr = ptr->link;
        ++idx;
    }
    temp->link = ptr->link;
    ptr->link = temp;
    return;
}

void reverse(Node *head)
{
    Node *nxt;
    Node *prev;
    Node *ptr;
    ptr = head;
    prev = NULL;
    while (ptr != NULL)
    {
        nxt = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = nxt;
    }
    head = prev;
    return;
}