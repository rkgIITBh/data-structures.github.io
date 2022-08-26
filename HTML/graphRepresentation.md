## Computer Representation of Graphs

Let us discuss some well known properties of an undirected graph before exploring the ways to process a
graph. 

<strong>Degree property</strong>: An undirected graph has even number of vertices of odd degrees.

The proof of the above property is simple. If we add the degrees of all vertices then 

<p style="text-align:center">
    &Sigma; deg[v] mod 2 = 0 (the sum is an even number, why?)
</p>

But summing of degrees of all even degree vertices gives an even number. It implies that the sum of 
degrees of all odd degree vertices must also be an even number. It implies that there can be only even
number of odd degree vertices.
            
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


