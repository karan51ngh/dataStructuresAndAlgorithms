//preprocessor statements
#include <stdio.h>
#include <stdlib.h>
//typedef statements
typedef struct adjListNode adjListNode;
typedef struct adjList adjList;
typedef struct graph graph;
//structures for graph,list,list Node
struct adjListNode //Node of the adjacency lists
{
    int name;
    adjListNode *link;
};
struct adjList //the adjacency list
{
    adjListNode *head; //pointer to a linked list
};
struct graph //graph is an array of adjecency lists
{
    int v;
    adjList *glist; //dynamic form of array-----check
};
//functions
graph *initGraph(graph *, int);
void addEdge(graph *, int, int);
void printGraph(graph *);
adjListNode *getAdjListNode(int);
//program
void main()
{
    int v = 5, ch, i, j;
    graph *g;
    g = initGraph(g, v);
    printf("do you want to add edges?\nenter 1/0 :\n");
    scanf("%d", &ch);

    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    // addEdge(g, 1, 2);
    // addEdge(g, 1, 3);
    // addEdge(g, 1, 4);
    // addEdge(g, 2, 3);
    // addEdge(g, 3, 4);
    printGraph(g);
}
graph *initGraph(graph *g, int v)
{
    g = (graph *)malloc(sizeof(graph));
    g->v = v;
    g->glist = (adjList *)malloc(v * sizeof(adjList));
    for (int i = 0; i < v; i++)
    {
        g->glist[i].head = NULL;
    }
    return g;
}
adjListNode *getAdjListNode(int i)
{
    adjListNode *newNode = (adjListNode *)malloc(sizeof(adjListNode));
    newNode->name = i;
    newNode->link = NULL;
    return newNode;
}
void addEdge(graph *g, int src, int dest)
{
    adjListNode *newNode = getAdjListNode(dest);
    newNode->link = g->glist[src].head;
    g->glist[src].head = newNode;

    newNode = getAdjListNode(src);
    newNode->link = g->glist[src].head;
    g->glist[dest].head = newNode;
}
void printGraph(graph *g)
{
    for (int i = 0; i < g->v; i++)
    {
        adjListNode *crawl = g->glist[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (crawl)
        {
            printf("-> %d", crawl->name);
            crawl = crawl->link;
        }
        printf("\n");
    }
}
