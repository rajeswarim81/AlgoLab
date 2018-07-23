#include<iostream>
#include<climits>
#include<cmath>
#include<cstring>
#include<stdlib.h>

using namespace std;


struct adjlistnode{
	int data;
	struct adjlistnode *next;
};


struct adjlist{
	 struct adjlistnode *head;
};

struct Graph{
	int v;
    struct adjlist *array;;
};


void addEdge(struct Graph *graph, int src, int dest){

    adjlistnode *node_src = new adjlistnode;
    adjlistnode *node_dest = new adjlistnode;

    node_src->data=dest;
    node_dest->data=src;

    node_src->next=NULL;
    node_dest->next=NULL;

    node_src->next=graph->array[src].head;
    graph->array[src].head=node_src;

  //  cout<<graph->array[src].head->data;

    node_dest->next=graph->array[dest].head;
    graph->array[dest].head=node_dest;
    //cout<<graph->array[dest].head->data;

   // delete(node_src);
   // delete(node_dest);
    
}
struct Graph* createGraph(int V)
{
	//struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	Graph *graph = new Graph;
	graph->v = V;

	// Create an array of adjacency lists. Size of array will be V
	graph->array = (struct adjlist*) malloc(V * sizeof(struct adjlist));
    //graph->array=new adjlist;
	// Initialize each adjacency list as empty by making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void printGraph( Graph* graph)
{
	int i;
	for (i = 0; i < graph->v; ++i)
	{
		adjlistnode* pCrawl = graph->array[i].head;
		cout<<"\n Adjacency list of vertex "<<i<<"\nhead ";
		while (pCrawl)
		{
			cout<<"->"<<pCrawl->data;
			pCrawl = pCrawl->next;
		}
		cout<<"\n";
	}
}

int main()
{
	//int v=5;
   struct Graph *graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);


    printGraph(graph);
	return 0;
}