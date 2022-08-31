## A Few Simple Properties of a Graph and Computer Representation of a Graph

Let us discuss some well known properties of an undirected graph before exploring the ways to process a
graph. 



<strong>Graph property-1</strong>: An undirected graph has even number of vertices of odd degrees.

The proof of the above property is simple. If we add the degrees of all vertices then 

<p style="text-align:center">
    &Sigma; deg[v] mod 2 = 0 (the sum is an even number, why?)
</p>

But summing of degrees of all even degree vertices gives an even number. It implies that the sum of 
degrees of all odd degree vertices must also be an even number. It implies that there can be only even
number of odd degree vertices.
      
<strong>Graph property-2</strong>: Let <i>G</i> be a graph with <i>n</i> vertices and assume that the
degree of each vertex is at least &LeftCeiling;<i>(n-1)/2</i>&RightCeiling; then the graph is connected.

Let <i>n=2k</i>, for <i>k=1, 2, ...</i>. Let <i>G</i> be disjoint union of two complete subgraphs both having
<i>k</i> vertices. Then the degree of each vertex in <i>G</i> is at least <i>k-1</i>. However <i>G</i> is 
disconnected. So to have <i>G</i> connected the minimum vertex degree should be <i>k</i>. 

Now consider the case when <i>G</i> has <i>2k-1</i> vertices. Again let <i>G</i> be disjoint union of two 
complete subgraphs, one having <i>k</i> and other having <i>k-1</i> vertices. The minimum vertex degee 
required for this to be true is <i>k-2</i>. So, the minimum vertex degree required for <i>G</i> to be 
connected is <i>k-1</i>.

Combining the two cases the minimum vertex degree required for <i>G</i> to be connected is:

- <i>n/2</i> when <i>n</i> is even, and 
- <i>(n-1)/2</i> when <i>n</i> is odd. 

The two conditions for connectivity can be expressed together as &LeftCeiling; (n-1)/2 &RightCeiling;

<strong>Graph property-3</strong>: A connected graph with <i>n</i> vertices has at least
<i>n-1</i> edges.

Let <i>G</i> have 1 vertex. It is obviously connected. So, the property holds. Now let <i>G</i> be
a graph with <i>n &ge; 2</i> vertices. Choose an arbitrary vertex <i>v</i> from <i>G</i>. Consider
the subgraph <i>H = G - {v}</i>. <i>H</i> may consist of <i>k</i> connected components
<i>Z<sub>i</sub></i>. Assume that <i>Z<sub>i</sub></i> has <i>n<sub>i</sub></i> vertices. By 
the induction hypothesis each <i>Z<sub>i</sub></i> has at least <i>n<sub>i</sub>-1</i> edges. The 
total number of vertices in subgraphs is equal to

<p style="text-align:center">
    &Sigma;<sub>i</sub> (n<sub>i</sub>) = n-1  
</p>
To connect the vertex <i>v</i> to each of the subgraphs <i>Z<sub>i</sub></i> we require 
one edge. So, the minimum number of edges required to make <i>G</i> connected is 
<p style="text-align:center">
    &Sigma;<sub>i</sub> (n<sub>i</sub> - 1) + k = n-1 - k + k = n-1</i> 
</p>

We can continue discussion on more graph properties. But our focus is graph algorithms. So we stop
the discussion on graph properties for the moment. Let us focus on the computer processing of graphs.
First and foremost question is: how to represent a graph as an abstract datatype?

A graph essentially represents relationships between objects or things. We can use a matrix to capture 
relationships between objects. Therefore, the standard form for computer representation of a graph with
<i>n</i> vertices is a matrix of size <i>n<sup>2</sup></i>. An entry 
<p style="text-align:center">
            <i>a[i, j] = 1</i> if there is edge <i>(i, j) &isin; E</i><br>
            <i>a[i, j] = 0</i> otherwise
            </p> 
In other words, the <i>ij</i>th entry is 1 if the object <i>i</i> is related to the object <i>j</i>. In
the pictorial representation we denote the relationship by an edge joining the related objects. The absence 
of edge is indicated by a 0 entry. The matrix is called adjacency matrix because it represent the 
relationship if a vertex is adjacent to another. Figure 1 illustrates the adjacency matrix representation.
<p style="text-align:center">
   <img src="../images/adjacencyMatrix.png">
</p>
Processing of a graph requires every entry of the adjacecny matrix to be accessed. So the any graph 
algorithm requires time of at least O(<i>n<sup>2</sup></i>). 

However, if the graph is sparse, then most entries of adjacency matrix are zero. So, representing graphs
using matrix is expensive. We can use a representation which lists the edges incident at every vertex. 
The adjacency list representation of a graph consists of <i>n</i> lists, one corresponding to each vertex.
Every edge is listed twice in such a representation. Adjacency list representation of the graph in 
Figure 1 is given below.
<p style="text-align:center">
   <img src="../images/adjacencyList.png">
</p>

[Back to Index](../index.md)
