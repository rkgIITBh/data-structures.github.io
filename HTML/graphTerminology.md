## Graph Terminology

It is convenient to introduce a bunch of terminology in connection with graphs. We will only be 
concerned with undirected graphs. However, for each terminology we describe here, a corresponding
terminology exists for the directed graphs. We will deal with directed graphs at a later point
of time. 

The processing of graph data structures is heavily dependent on ability to quickly and systematically
access vertices of graph starting with any initial vertex. Therefore, graph search or accessibility of 
the vertices of a graph structure from one or different vertices is extremely important. The 
accessibility or reachability in a graph is defined in differnt context as follows:

<strong>Path</strong>: There is a path from a vertex <i>v</i> to another vertex <i>w</i> if there is
a sequence of vertices <i>v, v<sub>1</sub>, v<sub>2</sub>, ..., v<sub>k</sub>, w</i> such that there 
exists edges between every pair of adjacent vertices of the sequence. That is, the graph has the 
following edges:

- <i>(v,v<sub>1</sub>) &isin; E</i>, 
- <i>(v<sub>i</sub>,v<sub>i+1</sub>) &isin; E</i>, for <i>1 &le; i &le; k-1</i>, and 
- <i>(v<sub>k</sub>, w) &isin; E</i>.

<strong>Simple path</strong>: A path is called a simple path if every vertex on the given path is distinct.

<strong>Length of a path</strong>: The number edges on a path is equal to its length. 
So if a path represented by a sequence of <i>k</i> vertices then its length is <i>k-1</i>. 


<strong>Simple cycle</strong>: A simple cycle is a simple path where the two end vertices are also 
connected with an edge. 

<strong>Connected graphs</strong>: A graph <i>G</i> is connected if and only if there exists a
path between every pair of vertices in <i>G</i>.

<strong>Subgraph</strong>: A graph <i>H = (V<sub>1</sub>, E<sub>1</sub>)</i> is a subgraph of a
graph <i>G=(V, E)</i>, if <i>V<sub>1</sub> &#8838; V</i> and <i>E<sub>1</sub> &#8838; E</i>.

<strong>Connected component</strong>: A maximally connected subgraph of a graph is known as a 
connected component of the graph. The maximality of a subgraph means that if we add one more vertex 
from the graph to the subgraph then it no longer remain connected.

Let us check some of the examples to understand the definitions we have learned so far. We begin
with an example of a graph in the picture below.
<p style="text-align:center">
  <img src="../images/graphExample1.png"><br>
  Figure 1
</p>
The graph shown above is a disconnected graph as there is no path connecting vertex <i>a</i> to any of
the vertices <i>f</i> or <i>g</i> or <i>h</i>. The graph has two connected components as marked H<sub>1</sub>
and H<sub>2</sub> in the picture. Clearly, there is a path between every pair of vertices belonging either to
H<sub>1</sub> or H<sub>2</sub>. However, if we add vertex <i>c</i> to subgraph H<sub>2</sub> then it does
remain connected. Similarly, if adding <i>g</i> to subgraph H<sub>1</sub> lead it to become disconnected.
There is a simple cycle between vertices <i>f, g, h</i>. The subgraph H<sub>1</sub> has many simple cycles. 
One example for a cycle of length 5 is <i>a, c, d, e, b</i>. 


