## Amortised Time Complexity for Splay Trees

The contents of this blog are a bit mathematical and require a bit of maturity in understanding. We
have discussed splaying operation in a previous blog. In course of discussion we mentioned that
splay tree data structure support a sequence of O(<i>m</i>) operations in average O(<i>log n</i>)
unit of time per operation or overall time of O(<i>m log n</i>) time. In a completely left or right
skewed tree, the time for accessing the leaf node could be as expensive as O(<i>n</i>), where 
<i>n</i> is the number of nodes in the tree. The average time we mentioned is amortized 
time or time partitioned over a sequence of operations. If we consider an operation in isolation, then
the average bound does not work. So, we need to provide an analysis of the amortized time.

We start with a potential function. A potential function is reserve energy, as a physicist 
may define it. The reserve energy tells us a system's intrinsic capabilities to work. When we execute 
some activities, potentials reduce. We can increase our potential by eating nutritious food and
training under a physical trainer. The amortized cost relies on doing some expensive activities to make
future activities easier. 
  
How do we define a potential for operations on splay trees? The operations supported by splay trees
normal BST operations of search, insert, and delete. These operations depend on the length of the
tree path from the root to the accessed node.  In the worst-case, it is equal to the height of the tree. So, we define the potential by the following function
<p align="text:center">
  &#x3D5;(T) = &Sigma;log(<i>S(i)</i>)
</p>
Where <i>S(i)</i> denotes the number of descendants of <i>i</i> (including itself). Let us define 
log <i>S(i)=R(i)</i>, where <i>R(i)</i> is the rank (or height) of node <i>i</i>. Thus <i>R(T)</i>
is the height of the tree <i>T</i>. 

We need a preliminary result for our analysis given in Lemma 1.

<strong>Lemma 1</strong>: If <i>a + b &le; c</i> where <i>a</i> and <i>b</i> are both positive
integers then log <i>a</i> + log <i>b</i> &lt; 2log <i>c</i> - 2.

<strong>Proof</strong>: We know the arithmetic mean is less than equal to the geometric mean. So,
&radic;(<i>ab</i>) &le; <i>(a+b)/2</i> &le; <i>c/2</i>. Taking square of both side of previous 
inequality, we have <i>ab</i> &le; <i>c<sup>2</sup>/4</i>. Now take the log of both sides to get
the result.

The fundamental operations for spalying
are zig, zig-zig, and zig-zag. Let us focus on the complexity of these operations. 

Let the ranks and sizes of a node <i>x</i> be denoted respectively by:

- Before splaying: <i>R<sub>i</sub>(x)</i> and <i>S<sub>i</sub>(x)</i> 
- After splaying: <i>R<sub>f</sub>(x)</i> and <i>S<sub>f</sub>(x)</i> 

<strong>Zig step</strong>: For completeness of description, zig type splaying is shown in the figure
below. 
<p style="text-align:center">
  <img src="../images/R-splay.png">
</p>
The actual time for the zig step is 1 because it is a rotation. The computation of potential 
change is easy. The splaying affects subtrees under <i>x</i> and <i>p</i>. 
The average time <i>AT<sub>zig</sub></i> is equal to the potential change for subtrees under
two subtrees. Therefore,
<div style="text-align:center">
  <i>AT<sub>zig</sub> &le; 1+R<sub>f</sub>(x) + R<sub>f</sub>(p) - R<sub>i</sub>(x) - R<sub>i</sub>(p)</i>
</div>
The size of the subtree of <i>p</i> decreases after splaying. So we have 
<i>R<sub>f</sub>(p) &lt; R<sub>i</sub>(p)</i>. However, the size of subtree of <i>x</i>
increases. So, <i>R<sub>f</sub>(x) &gt; R<sub>i</sub>(x)</i>. We can now simplify the
expression for average time <i>AT<sub>zig</sub></i> for zig type splaying as follows:
<div style="text-align:center">
  <i>AT<sub>zig</sub> &lt; 1+R<sub>f</sub>(x) - R<sub>i</sub>(x)</i>
</div>
Since <i>R<sub>f</sub>(x) - R<sub>i</sub>(x)</i> we conclude that 
<div style="text-align:center">
  <i>AT<sub>zig</sub> &lt; 1+3(R<sub>f</sub>(x) - R<sub>i</sub>(x))</i>
</div>

<strong>Zig-zag step</strong>: A zig-zig type splaying requires a double rotation, as shown in 
the image below. 
<p style="text-align:center">
  <img src="../images/LR-splay.png">
</p>
The actual time for zig-zag is 2 (double rotation). The potential change occurs for three subtrees
under <i>x</i>, <i>p</i> and <i>g</i>. The reader can observe that the following expression gives potential change.
<div style="text-align:center">
  <i>2+R<sub>f</sub>(x) + R<sub>f</sub>(p) + R<sub>f</sub>(g) - R<sub>i</sub>(x) - R<sub>i</sub>(p) - R<sub>i</sub>(g)</i> 
</div>
From the figure we observe <i>S<sub>f</sub>(p) + S<sub>f</sub>(g) &lt; S<sub>f</sub>(x)</i>. Therefore, from the above lemma, we can conclude:
<i>log S<sub>f</sub>(p) + log S<sub>f</sub>(g) &lt; 2 log S<sub>f</sub>(x) - 2</i>. Since log <i>Size = height</i>, we have <i>R<sub>f</sub>(p) + R<sub>f</sub>(g) &lt; 2R<sub>f</sub>(x)-2</i>.

Summarizing the observation from the figure, we get the following:

- <i>R<sub>f</sub>(x) = R<sub>i</sub>(g)</i>.
- <i>R<sub>i</sub>(g) &gt; R<sub>i</sub>(x)</i>.
- <i>R<sub>f</sub>(p) + R<sub>f</sub>(g) &lt; 2R<sub>f</sub>(x) - 2</i>.

Substituting <i>R<sub>f</sub>(g)</i> for <i>R<sub>f</sub>(x)</i>, we get
<div style="text-align:center">
  <i>2 + R<sub>i</sub>(g) +  R<sub>f</sub>(p) + R<sub>f</sub>(g) - R<sub>i</sub>(x) - R<sub>i</sub>(p) - R<sub>i</sub>(g)</i> <br>
  <i>&le; 2 + R<sub>f</sub>(p) + R<sub>f</sub>(g) - R<sub>i</sub>(x) - R<sub>i</sub>(p)</i><br>
  <i>&le; 2(R<sub>f</sub>(x) - R<sub>i</sub>(x))</i>
</div>
Since <i>R<sub>f</sub>(x) - R<sub>i</sub>(x) &gt; 0</i>, we have
<div style="text-align:center">
  <i>AT<sub>zig-zag</sub> &le; 3(R<sub>f</sub>(x) - R<sub>i</sub>(x))</i>
  </div>
  
  <strong>Zig-zig</strong>: Analysis of zig-zag step is similar to that for zig-zag. Amortized cost
  of a single zig, or zig-zag or zig-zag splay is bounded above by <i>3(R<sub>f</sub>(x) - R<sub>i</sub>(x))</i>.
  
Let us examine the example of splaying given below:
<p style="text-align:center">
  <img src="../images/splayExample2.png">
</p>
Let the four trees be denoted by  <i>T<sub>1</sub></i>, <i>T<sub>2</sub></i>, <i>T<sub>3</sub></i>, and
<i>T<sub>4</sub></i>
Consider the rank of node 1 in the four trees. It requires three zig-zag splays with 
respective costs:

  - 3(<i>R<sub>2</sub>(1) - R<sub>1</sub>(1)</i>),
  - 3(<i>R<sub>3</sub>(1) - R<sub>2</sub>(1)</i>), and
  - 3(<i>R<sub>4</sub>(1) - R<sub>3</sub>(1)</i>).
 
Telescoping addition of three expressions we get final cost as 
3(<i>R<sub>4</sub>(1) - R<sub>1</sub>(1)</i>). Then we add
actual access cost of telescoped sum to get the final expression 1 +  3(<i>R<sub>4</sub>(1) - R<sub>1</sub>(1)</i>). It is of the order of
O(log <i>n</i>). Since every operation on the splay tree requires splaying, the amortized cost of 
any operation on a splay tree is O(log <i>n</i>) where <i>n</i> is the number of nodes in the 
tree.

[Back to Index](../index.md)
