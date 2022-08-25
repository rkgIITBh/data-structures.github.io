## Graphs

Any relationship between objects or things can be represented using graphs. Suppose for instance,
we want to pictorially represent the relationship such as siblings (brothers or sisters) among a 
set of six people. We denote each person by a small point or bubble as shown in the figure below.
For conveninence, let us label the bubbles as <i>a, b, c, d, e, f</i>. To express the sibling 
relationship between <i>a</i> and <i>b</i>, draw a line connecting the corresponding bubbles. 
<p style="text-align:center">
  <img src="../images/siblingGrpah.png">
</p> 
The figure also represents other sibling relations.

The concept graphs representing relationships is very generic. We can use bubbles to denote different
things and link the bubbles for expressing different relations. For convenience we use the term 
<i>vertex</i> for a bubble and the <i>edge</i> to denote a line joining a pair of vertices. In 
general, a graph shown in the figure above may represent different relationship depending on the
context we use.  

- The vertices may represent computers and the edges may denote if a pair of computers are directly connected. 
- Vertices may even represent cities in state and the edges denote whether direct train connectivity exists between a pair of cities.

We may also use graphs for representing relationship between dissimilar objects. For example, the
graph below has two set of vertices: one set representing banks the other set as clients of the
banks. The edges between vertices denote bank and customer relationships.
<p style="text-align:center">
  <img src="../images/bankClientGrpah.png">
</p> 

In general, the graph abstraction is very powerful. In dealing with complex data structures, we 
find the abstraction allows us to link the complex relationships among objects. So, we need to
define and build graph data structures from general abstraction of graph. Before we proceed 
further, let us introduce graph terminology. 
