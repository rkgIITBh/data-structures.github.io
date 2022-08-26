## Computer Representation of Graphs

Let us discuss some well known properties of an undirected graph before exploring the ways to process a
graph. 

<strong>Degree property</strong>: An undirected graph has even number of vertices of odd degrees.

The proof of the above property is simple. If we add the degrees of all vertices then 

<p style="text-align:center">
            &Sigma; deg[v] is an even number
</p>

But summing of degrees of all even degree vertices gives an even number. It implies that the sum of 
degrees of all odd degree vertices must also be an even number. It implies that there can be only even
number of odd degree vertices.
            
A graph essentially represents relationships between objects or things. We can use a matrix to capture 
relationships between objects. Therefore, the standard form for computer representation of a graph with
<i>n</i> vertices is a matrix of size <i>n<sup>2</sup></i>. An entry <i>a[i, j] = 1</i> if and only if
the object <i>i</i> is related to the object <i>j</i>. In the pictorial representation we denote the 
relationship by an edge joining the related objects. Therefore, the matrix entry <i>a[i, j] = 1</i> implies 
that the there is an edge between vertices <i>i</i> and <i>j</i>. The absence of edge is indicated by
<i>a[i, j] = 0</i>. The matrix is called adjacency matrix because it represent the relationship if a
vertex is adjacent to another. Processing of a graph requires every entry of the adjacecny matrix to be
accessed. So the any graph algorithm requires time of at least O(<i>n<sup>2</sup></i>. However, if the
graph is sparse then the number of edges may of equal to the order of the number of vertices. So, representing
graphs using matrix is expensive.
