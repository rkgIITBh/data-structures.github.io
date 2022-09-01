## Code for Graph Data Structure

The program prints undirected (u), directed (d) and weighted (w) graphs. Give the type of graph
that you would like to print as an input. The edges with weights are hard-coded in the program.
The program should be modified for taking user input if needed.

```
#include <stdio.h>
#include <stdlib.h>

// Maximum number of vertices in the graph
#define N 6

// Define datatype for a node in a graph 
typedef struct node {
	int dest;
    int weight;
	struct node* next;
} NODE;


// Define datatype graph to store its nodes and adjacency lists
typedef struct graph
{
	// An array of pointers to represent adjacency lists
	NODE* head[N];
} GRAPH;

// Data structure to store a graph edge
typedef struct edge {
	int src, dest, weight;
} EDGE;

// Creates an adjacency list from given edges
GRAPH* createGraph(EDGE edges[], int n, int flag) {
	// Allocate storage for the graph data structure
	GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));

	// Initialize head for all vertices
	for (int i = 0; i < N; i++) {
		graph->head[i] = NULL;
	}

	// Add edges to the directed graph one by one
	for (int i = 0; i < n; i++) {
		// Get the source and destination 
		int src = edges[i].src;
		int dest = edges[i].dest;
		int weight = edges[i].weight;

		// Allocate a new node of adjacency list from src to dest

		NODE* newNode = (NODE*)malloc(sizeof(NODE));
		newNode->dest = dest;
		newNode->weight = weight;

		// Point new node to the current head
		newNode->next = graph->head[src];

		// Point head to the new node
		graph->head[src] = newNode;

		// Allocate a new node of adjacency list from `dest` to `src`
        	if (flag==0) {
		    newNode = (NODE*)malloc(sizeof(NODE));
	    	    newNode->dest = src;
		    newNode->weight = weight;

	    	    // Point new node to the current head
	    	    newNode->next = graph->head[dest];

	    	    // Change head to point to the new node
	    	    graph->head[dest] = newNode;
               } 

	}
	return graph;
}

// Prints adjacency lists of a graph
void printGraph(GRAPH* graph, int w) {
	for (int i = 0; i < N; i++) {
		// Prints the current vertex its neighbors
		NODE* ptr = graph->head[i];
		if (!w) {
            		// Print unweighted graph
            		while (ptr != NULL) {
			    	printf("(%d —> %d)\t", i, ptr->dest);
			    	ptr = ptr->next;
		        }
        	} else {
            		// Print weighted graph
            		while (ptr != NULL) {
                		printf("%d —> %d (%d)\t", i, ptr->dest, ptr->weight);
                		ptr = ptr->next;
           	        }
        	}
      		printf("\n");
	}
}

// Directed graph implementation in C
int main(void) {
    GRAPH * graph; // Define storage for a graph 
                   
	// Input containing edges of the graph 
	// (x, y) represents an edge from x to y
	EDGE edges[] = {
		{0, 1, 0}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {4, 5, 1}, {5, 4, 3}
	};

	// The total number of edges
	int n = sizeof(edges)/sizeof(edges[0]);
    char t;
    printf("Enter graph type (d/u/w):");
    scanf("%c",&t);
    if (t == 'u') {
       
         // Undirected graph type
	     graph = createGraph(edges, n, 0);

         printf("Print Undirected graph\n");
         printf("---------------------\n");
         
         // Prints adjacency lists
    	 printGraph(graph);
    } else if (t=='d') {
        
         // Directed graph type
         printf("Print Directed graph\n");
         printf("-------------------\n");
         graph = createGraph(edges, n, 1);

         // Prints adjacency lists
	     printGraph(graph);
    } else {
        
         // Weighted graph type
         printf("Print weighted graph\n");
         printf("-------------------\n");
         graph = createGraph(edges, n, 2);

         // Prints adjacency lists with weights
	     printWeightedGraph(graph);
    }

	return 0;
}

```
[Back to Graph Implementation](../../HTML/graphImplementation.md)
