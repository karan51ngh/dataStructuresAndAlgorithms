#include <stdio.h>
#include <stdlib.h>
//typedef
typedef struct Node Node;
typedef struct graph graph;
//structures
struct Node
{
    int dest;
    Node *link;
};
struct graph
{
    int dest;
    Node **list;
};
//functions
graph *initGraph(graph *, int);
Node *getNode(int);
void addEdge(graph *, int, int);
void printGraph(graph *);
//program
void main()
{
    system("cls");
    graph *g;
    int v, ch, src, dest;
    printf("enter the number of vertices in your graph\n");
    scanf("%d", &v);
    g = initGraph(g, v);
    printGraph(g);
    //  printf("enter 1/0 to create an edge\n");
    //scanf("%d", &ch);
    while (ch)
    {
        printf("enter the source node\n");
        scanf("%d", &src);
        printf("Enter the destination node\n");
        scanf("%d", &dest);
        addEdge(g, src, dest);
        printf("enter 1/0 to continue creating an edge\n");
        scanf("%d", &ch);
    }
    addEdge(g, 1, 0);
    printf("the graph is:\n");
    printGraph(g);
}
graph *initGraph(graph *g, int v)
{
    g = (graph *)malloc(sizeof(graph)); //forgetting this wont allow the next line
    g->dest = v;
    g->list = (Node **)malloc((g->dest) * sizeof(Node *));
    for (int i = 0; i < g->dest; i++)
    {
        g->list[i] = NULL;
    }
    return (g);
}
Node *getNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->link = NULL;
    return (newNode);
}
void addEdge(graph *g, int src, int dest)
{
    // Node *newNode = (Node *)malloc(sizeof(Node));
    // newNode->dest = dest;
    Node *newNode = getNode(dest);
    newNode->link = g->list[src];
    g->list[src] = newNode;
    newNode->dest = src;
    newNode->link = g->list[src];
    g->list[dest] = newNode;
}
void printGraph(graph *g)
{
    for (int i = 0; i < g->dest; i++)
    {
        printf("%d head", i);
        Node *crawl = g->list[i];
        while (crawl != NULL)
        {
            printf("->%d", crawl->dest);
            crawl = crawl->link;
        }
        printf("\n");
    }
}