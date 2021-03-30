#include <stdio.h>
#include <stdlib.h>
//typedef statements
typedef struct graph graph;
typedef struct adjListNode adjListNode;
typedef struct adjList adjList;
//structures
struct graph
{
    int v;
    adjList *glist;
};
struct adjListNode
{
    int dest;
    adjListNode *link;
};
struct adjList
{
    adjListNode *head;
};
//functions
graph *initGraph(graph *, int);
adjListNode *getAdjListNode(int);
void addEdge(graph *, int, int);
void printGraph(graph *);
//program
void main()
{
    system("cls");
    int v = 5, ch, i, j;
    graph *g;
    g = initGraph(g, v);
    printf("do you want to add edges?\nenter 1/0 :\n");
    scanf("%d", &ch);
    while (ch)
    {
        printf("enter the 1st and the 2nd Node to add an edge in between\n");
        scanf("%d", &i);
        scanf("%d", &j);
        addEdge(g, i, j);
        printf("do you want to continue adding edges? enter 1/0 :\n");
        scanf("%d", &ch);
    }
    printf("the graph is:\n");

    printGraph(g);
}
graph *initGraph(graph *g, int v)
{
    g->v = v;
    g->glist = (adjList *)malloc((g->v) * sizeof(adjList));
    for (int i = 0; i < g->v; i++)
    {
        g->glist[i].head = NULL;
    }
    return (g);
}
adjListNode *getAdjListNode(int dest)
{
    adjListNode *newNode;
    newNode = (adjListNode *)malloc(sizeof(adjListNode));
    newNode->dest = dest;
    newNode->link = NULL;
    return (newNode);
}
void addEdge(graph *g, int src, int dest)
{
    adjListNode *newNode;
    newNode = getAdjListNode(dest);
    newNode->link = g->glist[src].head;
    g->glist[src].head = newNode;

    newNode = getAdjListNode(src);
    newNode->link = g->glist[dest].head;
    g->glist[dest].head = newNode;
}
void printGraph(graph *g)
{
    printf("entered the print func\n");
    for (int i = 0; i < g->v; i++)
    {
        adjListNode *crawl;
        crawl = g->glist[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (crawl)
        {
            printf("->%d", crawl->dest);
            crawl = crawl->link;
        }
        printf("\n");
    }
}