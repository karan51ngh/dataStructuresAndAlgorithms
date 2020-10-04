//pre-processor stat
#include <stdio.h>
#include <stdlib.h>
//typedef stat
typedef struct Node Node;
typedef struct graph graph;
//structures
struct Node //Node for graph-lists and queue
{
    int dest;
    Node *link;
};
struct graph //graph
{
    int V;
    Node **glist;
};
//functions
graph *initGraph(graph *, int);     //initializing the graph
Node *getNode(int);                 //to get the node
void addDirEdge(graph *, int, int); //to add an edgge
void printGraph(graph *);           //to print graph
int *updateVisit(int *, int);       //to update the visited array
void enque(Node **, int);           //to enque into queue
int deque(Node **);                 //to deque out of queue
int notEmpty(Node **);              //checks whether the queue is empty
int notVisited(int *, int);         //checks wether a vertex has been visited or not
void bfs(graph *);                  //for traversing the graph, breadth first search from index 0
//programs
void main()
{
    system("cls");
    int v, ch, src, dest;
    graph *g;
    printf("enter the number of vertices");
    scanf("%d", &v);
    g = initGraph(g, v); //initializing graph
    printf("wanna add edges? enter 1/0\n");
    scanf("%d", &ch);
    while (ch) //user enters edges
    {
        printf("enter the source\n");
        scanf("%d", &src);
        printf("enter the destination\n");
        scanf("%d", &dest);
        addDirEdge(g, src, dest);
        printf("wanna continue? enter 1/0\n");
        scanf("%d", &ch);
    }
    printGraph(g);
    bfs(g);
}
graph *initGraph(graph *g, int v)
{
    g = (graph *)malloc(sizeof(graph));
    g->V = v;
    g->glist = (Node **)malloc(v * sizeof(Node *));
    for (int i = 0; i < v; i++)
    {
        g->glist[i] = NULL;
    }
    return (g);
}
Node *getNode(int dest)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->dest = dest;
    node->link = NULL;
    return (node);
}
void addDirEdge(graph *g, int src, int dest)
{
    Node *temp = getNode(dest);
    temp->link = g->glist[src];
    g->glist[src] = temp;
}
void printGraph(graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        Node *p;
        p = g->glist[i];
        printf("->");
        while (p != NULL)
        {
            printf("%d->", p->dest);
            p = p->link;
        }
        printf("NULL\n");
    }
}
int *updateVisit(int *arr, int d)
{
    arr[d] = 1;
    return (arr);
}
void enque(Node **q, int v)
{
    if (*q == NULL)
    {
        *q = getNode(v);
    }
    else
    {
        Node *t = *q;
        while (t->link)
        {
            t = t->link;
        }
        t->link = getNode(v);
    }
}
int deque(Node **q)
{
    if (*q == NULL) //queue has no element left
    {
        return (-1);
    }
    if ((*q)->link == NULL) //queue has 1 element left
    {
        int x = (*q)->dest;
        *q = NULL;
        return (x);
    }
    else //otherewise
    {
        Node *t = *q;
        Node *prev = *q;
        while (t) //t reaches NULL
        {
            prev = t; //prev will point to the node to be deleted
            t = t->link;
        }
        int x = prev->dest;
        t = *q; //reseting and reusing t
        while (t->link != prev)
        {
            t = t->link; //t will point to the Node previous to prev
        }
        t->link = NULL; //the lat Node is deleted(Not in memory but the link is broken)
        return (x);
    }
}
int notEmpty(Node **q)
{
    if ((*q) == NULL)
    {
        return (0);
    }
    else
    {
        return (1);
    }
}
int notVisited(int *arr, int d)
{
    return (!arr[d]);
}
void bfs(graph *g) //starting from vertex 0
{
    //initializing the queue
    Node **que;
    que = (Node **)malloc(sizeof(Node *));
    *que = NULL;
    //initializing the visited array
    int vis[100], i;
    for (i = 0; i < g->V; i++)
    {
        vis[i] = 0;
    }
    enque(que, 0);
    while (notEmpty(que))
    {
        int x = deque(que);
        if (notVisited(vis, x))
        {
            updateVisit(vis, x);
            printf("visited vertex %d\n", x);
        }
        Node *t = g->glist[x];
        while (t)
        {
            if (notVisited(vis, t->dest))
            {
                printf("visited vertex %d\n", t->dest);
                updateVisit(vis, t->dest);
                enque(que, t->dest);
            }
            t = t->link;
        }
    }
}
