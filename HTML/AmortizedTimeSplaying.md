## Amortised Time Analysis for Splay Trees

The contents of this blog is bit mathematical and requires a bit of maturity in understanding. We
have discussed splaying operation in a previous blog. In course of discussion we mentioned that
splay tree data structure support a sequence of O(<i>m</i>) operations in average O(<i>log n</i>)
unit of time per operation or overall time of O(<i>m log n</i>) time. In a completely left or right
skewed tree, the time for accessing the leaf node could be as expensive as O(<i>n</i>), where 
<i>n</i> is the number of nodes in the tree. The average time we mentioned is actually amortized 
time or time partitioned over a sequence of operations. If we consider an operation in isolation then
the average bound does not work. So, we need to provide an analysis of the amortized time.

We start with a potential function. A potential function is a kind of reserve energy as a physicist 
may define. The reserve energy tells us a system's intrinsic capabilities to work. When we execute 
some activities potentials reduce. We can increase potential by eating nutritious food and
train under a physical trainer. Amortised cost relies on doing some expensive activities to make
future activities easier. 
  
How we define a potential for operations on splay trees? The operations supported by splay trees
normal BST operations of search, insert and delete. These operations depend on the length of the
tree path from the root to the accessed node in the tree or the height of the tree in the 
worst-case. So, we define the potential by the following function
<p align="text:center">
  &#x3D5;(T) = &Sigma;log(<i>S(i)</i>)
</p>
Where <i>S(i)</i> denotes the number of descendants of <i>i</i> (including itself). Let us define 
log <i>S(i)=R(i)</i>, where <i>R(i)</i> is the rank (or height) of node <i>i</i>. Thus <i>R(T)</i>
is the height of the tree <i>T</i>. 

We need a preliminary result for our analysis which is given in Lemma 1.

<strong>Lemma 1</strong>: If <i>a + b &le; c</i> where <i>a</i> and <i>b</i> are both positive
integers then log <i>a</i> + log <i>b</i> &lt; 2log <i>c</i> - 2.

<strong>Proof</strong>: We know arithmetic mean is less than equal to geometric mean. So,
&radic;(<i>ab</i>) &le; <i>(a+b)/2</i> &le; <i>c/2</i>. Taking square of both side of previous 
inequality, we have <i>ab</i> &le; <i>c<sup>2</sup>/4</i>. Now take log of both side to get
the result.

We are ready to analyze the time for splaying. As explained already, the fundamental opreations 
are zig, zig-zig and zig-zag. So we focus on complexitie of these operations. 

Let the ranks and sizes of a node <i>x</i> be denoted respectively by:

- Before splaying: <i>R<sub>i</sub>(x)</i> and <i>S<sub>i</sub>(x)</i> 
- After splaying: <i>R<sub>f</sub>(x)</i> and <i>S<sub>f</sub>(x)</i> 

<strong>Zig step</strong>: Actual time for zig step is 1 because it is a rotation that involves
modification of three links. Notice that potential change is only respect to subtrees under <i>x</i> 
and its parent <i>p</i>. So the change in potential is easy to compute. It is:
<div style align="text:center">
  <i>1+R<sub>f</sub>(x) + R<sub>f</sub>(p) - R<sub>i</sub>(x) - R<sub>i</sub>(p)</i>
</div>
The size of the subtree of <i>p</i> increases after splaying. So we have <i>R<sub>f</sub>(p) &gt; R<sub>i</sub>(p)</i> 
Hence the amortised time for zig operation is bounded above by the expression:
<p style align="text:center">
  <i>R<sub>f</sub>(x) - R<sub>i</sub>(x) &gt; 0</i>
</p>
Since <i>R<sub>f</sub>(x) - R<sub>i</sub>(x)</i> we conclude that 
<div style align="text:center">
  <i>1+3(R<sub>f</sub>(x) - R<sub>i</sub>(x))</i>
</div>

<strong>Zig-zig step</strong>: Actual time for zig-zig is 2 (double rotation). The potential change
occurs at three subtrees under <i>x</i>, <i>p</i> and <i>g</i>. 
<div style align="text:center">
  <i>1+R<sub>f</sub>(x) + R<sub>f</sub>(p) + R<sub>f</sub>(g) - R<sub>i</sub>(x) - R<sub>i</sub>(p) - R<sub>i</sub>(g)</i> 
</div>
But the change in potential 

Let us consider the earlier example of splaying explained in <a href="./splayTree.md">Splay Trees</a>.
Suppose we apply splaying on node 2. The series of trees after each
splay is give below as <i>T<sub>1</sub></i>, <i>T<sub>2</sub></i>, <i>T<sub>3</sub></i>, and
<i>T<sub>4</sub></i>. Consider the rank of node 2 in the four trees. The first operation is a
zig-zag on tri-node configuration 2-1-4. Its cost is at most 3(<i>R<sub>2</sub> - R<sub>1</sub></i>).

  - Initial access cost for 2 is <i>R<sub>1</sub></i>
  - 
