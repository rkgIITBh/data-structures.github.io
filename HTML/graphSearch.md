## Graph Search

Graph seach is a fundamental step in processing a graph. The search is systematic traversal of the
edges and visit of vertices. The search should try to ensure that no vertex is visited more than its
degree times. However, each edge should be traversed at least once in the graph search. The two
requirement leads to the conclusion that a graph search is a systematic way to ensure an edge is 
traversed at least once and at most a constant number  of times (preferably &le; 2). 

Tremaux believed it is possible to trace out a path in a maze by a systematic exporation of the 
available routes. His solution is to unroll a ball of thread from entrance to exit. The method
he employed is to avoid every threaded route that led to a deadend. It helped him to avoid
all explored paths. So, he was able to find the exit.  
