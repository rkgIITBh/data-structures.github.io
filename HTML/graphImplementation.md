## Implementation of Graphs in C

The next thing we address is that of graph implementation in C. For a graph, we have three things
vertices, edges and weights associated with edges. We have not discussed about weighted graphs.
Weighted graphs are used for representation of transportations networks, computer network and
other variety of purposes where edge weight represent a quantification of the efforts needed for
going from one end vertex to another. Weighted graphs may be directed or undirected. The example 
of a weighted graph is shown in the picture below.
<p style="text-align:center">
  <img src="../images/weightedGraph.png">
</p>
The graph may be assumed to represent the distances between cities, where nodes are cities and 
edge labels are distances between cities it connects. The same graph may also represent a computer
network. The nodes are for computers and edges are for link between the pair of computers it
connects. An edge label denoting the RTT in milliseconds between the computers at the end vertices.
One can think of such a weighted graphs as a pipeline network representing quantities of flow of
oil or water or gas between end vertices of edges. So, weighted graphs have lot of applications. 
The most important problem one would like to solve in weighted graphs is shortest path. We will
return back to shortest path problem sometime later in the blog.

Having discussed about weighted graphs, let us examine the implementation issues. We assume graphs
as static structures unless specified otherwise. So, a graph can specified by 

- adjacency lists
- a list of edges
- adjacency matrix

When a graph is specified as a list of edges, we should first convert the graph to its adjacency
list or adjacency matrix representation. Because in most application, we process the graph from its
adjacency list representation.

We assume that the graph is specificed by edges (pair of end vertices) and the corresponding labels. 
The structure for implementation of graphs must have ability to store the three things, pair of 
end vertices and the edge label. The first end vertices is the considered as the source and the 
other is the destination. To represent the vertices, we require a data type <t>NODE</t>.
It stores the destination of an edge from the current node. The entire graph structure is defined 
by an array of node pointers. More specifically, <t>head[i]</t> denotes the adjacency list of node
<t>i</t> for <t>i = 0, 1, 2, ...</t>. Adjacency list of a vertex <t>i</i> is created by linking all
destination vertices of edges with source <t>i</t>. So, the data type <t>NODE</t> and <t>GRAPH</t>
as specified as follows.

```
typedef struct node {
	int dest; // Denotes the end vertex with which current vertex is connected
        int weight;
	struct node* next;
} NODE;

typedef struct graph {
	// An array of pointers to represent adjacency lists
	NODE* head[N];
} GRAPH;

```
