#include<stdio.h>
#include<stdlib.h>

/* for undirected graph */

typedef struct adj_list_node
{
    int id;
    struct adj_list_node* next;
}
adj_list_node;

typedef struct vertex
{
    int data;
    struct adj_list_node *next;
    struct adj_list_node *last;
}
vertex;

typedef struct Graph
{
    int size;
    struct vertex *node;
}
Graph;

void set_data(Graph* g)
{
    if(g->node != NULL)
    {
        int index = 0;
        for(int index=0;index<g->size;index++)
        {
            g->node[index].data = index;
            g->node[index].next = NULL;
            g->node[index].last = NULL;
        }
    }
    else
    printf("The graph is empty");
}

struct Graph* new_graph(int size)
{
    if(size<1)
    {
        printf("Invalid graph size");
        exit(0);
    }
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->size = size;
    g->node = (vertex*)malloc(sizeof(vertex)*size);
    set_data(g);
    return g;
}

void connect(Graph *g,int start,int last)
{
    adj_list_node *edge = (adj_list_node*)malloc(sizeof(adj_list_node));

    if(edge!=NULL)
    {
        edge->id = last;
        edge->next = NULL;

        if(g->node[start].next == NULL)
        {
            g->node[start].next = edge;
        }
        else
        {
            g->node[start].last->next = edge;
        }
        g->node[start].last = edge;
    }
    else
    printf("Memory overflow");
}

void addEdge(Graph* g,int start,int last)
{
    if(start<g->size && last<g->size)
    {
        connect(g,start,last);
    
    if(start==last)
    {
        return;
    }
    
    }
    else
    {
        printf("Invalid node vertices: %d, %d \t",start,last);
    }

}

void printgraph(Graph *g)
{
    if(g!=NULL)
    {
        adj_list_node *tmp = NULL;
        for(int index=0;index<g->size;index++)
        {
            printf("Vertex: %d\t",index);
            tmp = g->node[index].next;
            while(tmp!=NULL)
            {   
                printf("%d\t",g->node[tmp->id].data);
                tmp=tmp->next;
            }
            printf("\n");
        }
    }
    else
    printf("Emtpy graph");
}

void main()
{
    Graph *g = new_graph(5);
    addEdge(g,0,1);
    addEdge(g,1,2);
    addEdge(g,1,3);
    addEdge(g,3,4);
    addEdge(g,2,4);

    printgraph(g);
}