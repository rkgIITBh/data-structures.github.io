## Graph Terminology

It is convenient to introduce a bunch of terminology in connection with graphs. The processing
of graph data structures is heavily dependent on ability to quickly and systematically access vertices
of graph starting with any initial vertex. Therefore, graph search or accessibility of the vertices of
a graph structure from one or different vertices is extremely important. The accessibility or
reachability in a graph is defined in differnt context as follows:

<strong>Path</strong>: There is a path from a vertex <i>v</i> to another vertex <i>w</i> if there is
a sequence of vertices <i>v, v<sub>1</sub>, v<sub>2</sub>, ..., v<sub>k</sub> w</i> such that there 
exists edges between every pair of adjacent vertices of the sequence. That is, the graph has the 
following edges:

- <i>(v,v<sub>1</sub>) &isin; E</i>, 
- <i>(v<sub>i</sub>,v<sub>i+1</sub>) &isin; E</i>, for <i>1 &le; i &le; k-1</i>, and 
- <i>(v<sub>k</sub>, w) &isin; E</i>.
