## Graph Search

Graph seach is a fundamental step in processing a graph. The search is systematic traversal of the
edges and visit of vertices. The search should try to ensure that no vertex is visited more than its
degree times. However, each edge should be traversed at least once in the graph search. The two
requirement leads to the conclusion that a graph search is a systematic way to ensure an edge is 
traversed at least once and at most a constant number  of times (preferably &le; 2). 

Tremaux believed it is possible to trace out a path in a maze by a systematic exporation of the 
available routes. His solution is to unroll a ball of thread from entrance to exit. The method
he employed is to avoid every threaded route that led to a deadend. It helped him to avoid
all explored paths. So, he was able to find the exit. We construct an equivalent graph of a 
maze by associating a vertex with each intersection and joining every pair of vertices by an edge
if their corresponding intersections are directly reachable. An example of a maze and its 
equivalent graph is given below. The picture is taken from Chapter 4 of Rober Sedgewick and 
Kevin Wayne's text on algorithms. 
<p style="text-align:center">
    <img src="../images/tremaux.png">
</p>

Tremaux's graph exploration method was simplified later by 
Robert Tarjan. Tarjan noticed that the fundamental idea is to search the depth of graph until
it is not possible to go further, then retrace back and repeat exploration of the remaining 
graph via the first unexplored edge. Continue doing it until all edges are traversed and all
vertices are visited. Tarjan named it as depth first search. It traverses each edge exactly
twice and visits each vertex at most twice the degree times. 
