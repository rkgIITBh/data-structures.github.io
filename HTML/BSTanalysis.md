## Analysis of Binary Search Tree

For analysis of time complexity for operations on BST we explore the following questions.
- What could be a worst-case scenario?, and
- What could be a best-case scenario?

Search is the critical first step any operation including both insertion and deletion on a binary search tree. A successful or unsuccessful search depends on 
the length of the tree path from the root to the farthest leaf node. A right-skewed or a left-skewed BSTs exhibit pathological cases for insertions and 
deletions. These cases occur as follows:

- Perform an ascending sequence of <i>n</i> insertions on an initially empty BST it generates a right-skewed tree.
- Perform a descending sequence of <i>n</i> insertions on an initially empty BST it generates a left-skewed tree.

A completely skewed tree requires a time of <i>O(n)</i> for any operation. On the other hand, an operation on a balanced binary search tree takes <i>O(log n)</i>. Therefore, 

- A right-skewed or a left-skewed BST provides the worst-case scenario, and
- A balanced BST gives a best-case scenario for BSTs.

When we have a random input source, all distributions of the values are equally likely. So, it is important to analyze the average case time complexity. The
average case analysis of BST depends on the average path length traversed on a BST for performing an operation. We begin with an example. Consider the tree
shown below. The total internal path length of the tree is 15.
<p align="center">
<img src="../images/BSTinternalPath.jpg">
</p>

The first problem we need to address is:

- How to compute the internal path length of a BST in a dynamic situation where an operation can choose to traverse any section of a BST? 

We capture such a dynamic situation by considering the possibilities of insertions and deletions happening in any possible order. We use the following
assumptions:

- <i>P(n)</i>: the  average path length of a node in a BST with <i>n</i> nodes 
- Initial values are: <i>P(0) = 0</i> and <i>P(1)=1</i>.
- <i>x</i>: is the root of the BST or the first node to be inserted
- <i>x</i>: may equally likely to be 1st, 2nd, 3rd or <i>n</i>th element in the input  

Now consider <i>i</i>th insertion for a fixed <i>i</i> for <i>i = 0, 1, 2, ..., n-1</i>. The configuration of BST at this point is illustrated in 
the figure below:
<p align="center">
<img src="../images/averageCaseBST.jpg">
</p>
Consider how the subsequent insertion occurs.

- The root node will be probed in any case.
- If left subtree of the root is probed for <i>i+1</i> insertion then path length is <i>1+P(i)</i>
- If right subtree of the root is probed for <i>i+1</i> insertion then path length is <i>1+P(n-1-i)</i>
- The probability of searching any element is <i>1/n</i>.

So the average number of probes for <i>i+1</i>the insertion would be:
<p align="center">
<img src="https://latex.codecogs.com/svg.image?\begin{array}{ll}&space;P(n,i)&space;&&space;=&space;&plus;&space;\frac{i}{n}(1&space;&plus;&space;P(i))&space;&plus;&space;\frac{(n-i-1)}{n}(1&plus;P(n-i-1))\\&space;&space;&space;&space;&space;&space;&space;&&space;=&space;\frac{1&space;&plus;&space;i&space;&plus;&space;n&space;-&space;i&space;-&space;1}{n}&space;&plus;&space;\frac{i}{n}P(i)&space;&plus;&space;\frac{n-i-1}{n}&space;P(n-i-1)\\&space;&space;&space;&space;&space;&space;&space;&space;&&space;=&space;1&space;&plus;&space;\frac{i}{n}P(i)&space;&plus;&space;\frac{n-i-1}{n}P(n-i-1)\end{array}&space;" title="\begin{array}{ll} P(n,i) & = \frac{i}{n}(1 + P(i)) + \frac{(n-i-1)}{n}(1+P(n-i-1))\\ & = \frac{1 + i + n - i - 1}{n} + \frac{i}{n}P(i) + \frac{n-i-1}{n} P(n-i-1)\\ & = 1 + \frac{i}{n}P(i) + \frac{n-i-1}{n}P(n-i-1)\end{array} " />
  </p>

The average value is obtained by letting <i>i</i> to be any of the <i>n</i> elements. So, the average value is given by the expression:
<p align="center">
<img src="https://latex.codecogs.com/svg.image?&space;&space;P(n)=\frac{1}{n}\sum_i&space;P(n,i)" title=" P(n)=\frac{1}{n}\sum_i P(n,i)" />
 </p>
In the above equation, we use the expression found earlier to replace <i>P(n,i)</i>. Since the pair of sums for <i>P(i)</i> and <i>P(n,i)</i> are symmetric, the
simplified expression for <i>P(n)</i> becomes:
<p align="center">
<img src="https://latex.codecogs.com/svg.image?&space;&space;P(n)=&space;1&plus;\frac{2}{n^2}\sum_i&space;iP(i)" title=" P(n)= 1+\frac{2}{n^2}\sum_i iP(i)" />
</p>
  
Now apply induction to prove <img src="https://latex.codecogs.com/svg.image?P(n)&space;=&space;O(\log&space;n)" title="P(n) = O(\log n)" />. The induction 
requires a base case, an induction hypothesis and a proof for the induction step.

<b>Base case</b>: We know <i>P(1) = 1</i>,  and evaluation of the expression for <i>n=1</i> gives us: 
<p align="center"><img src="https://latex.codecogs.com/svg.image?1&plus;\frac{2}{n^2}\sum_i&space;iP(i)&space;=&space;1" title="1+\frac{2}{n^2}\sum_i iP(i) = 1" /></p>
<b>Induction hypothesis</b>: Assume 
<p align="center">
  <img src="https://latex.codecogs.com/svg.image?1&space;&plus;&space;4\log&space;i">
  </p>
  for any <i>i</i> less than <i>n</i>. 
  
 <b>Proof of induction step</b>: With the induction hypothesis in mind we apply to terms of the sum in the expression for <i>P(n)</i> and simplify it further
 to obtain: 
<p align="center">
<img src="https://latex.codecogs.com/svg.image?\begin{array}{ll}&space;&space;P(n)&space;&&space;\le&space;1&space;&plus;&space;\frac{2}{n^2}&space;\sum_{i=0}^{n-1}&space;i(1&plus;4\log&space;i)\\&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&&space;=&space;1&plus;\frac{2}{n^2}&space;\sum_{i=1}^{n-1}&space;4i\log&space;i&space;&plus;&space;\frac{2}{n^2}\sum_{i=0}^{n-1}&space;i\\&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&&space;\le&space;2&space;&plus;&space;\left(\frac{8}{n^2}\sum_{i=1}^{n-1}&space;i\log&space;i\right)&space;\mbox{,&space;since&space;}&space;\sum_{i=1}^{n-1}&space;i&space;\le&space;\frac{n^2}{2}&space;\\\end{array}" title="\begin{array}{ll} P(n) & \le 1 + \frac{2}{n^2} \sum_{i=0}^{n-1} i(1+4\log i)\\ & = 1+\frac{2}{n^2} \sum_{i=1}^{n-1} 4i\log i + \frac{2}{n^2}\sum_{i=0}^{n-1} i\\ & \le 2 + \left(\frac{8}{n^2}\sum_{i=1}^{n-1} i\log i\right) \mbox{, since } \sum_{i=1}^{n-1} i \le \frac{n^2}{2} \\\end{array}" />
</p>
Consider the sum on the right-hand side of previous inequality and apply simplification:
<p align="center">
<img src="https://latex.codecogs.com/svg.image?\begin{array}{ll}&space;&space;\sum_{i=1}^{n-1}&space;i\log&space;i&space;&=&space;&space;\sum_{i=1}^{\lceil\frac{n}{2}\rceil-1}&space;i\log&space;i&space;&plus;&space;\sum_{\lceil\frac{n}{2}\rceil}^{n-1}&space;i\log&space;i\\&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&&space;\le&space;\sum_{i=1}^{\lceil\frac{n}{2}\rceil-1}&space;i\log\frac{n}{2}&space;&plus;&space;\sum_{\lceil\frac{n}{2}\rceil}^{n-1}&space;i\log&space;n\\&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&&space;\le\frac{n^2}{8}\log\frac{n}{2}&space;&plus;&space;\frac{3n^2}{8}\log&space;n\end{array}" title="\begin{array}{ll} \sum_{i=1}^{n-1} i\log i &= \sum_{i=1}^{\lceil\frac{n}{2}\rceil-1} i\log i + \sum_{\lceil\frac{n}{2}\rceil}^{n-1} i\log i\\ & \le \sum_{i=1}^{\lceil\frac{n}{2}\rceil-1} i\log\frac{n}{2} + \sum_{\lceil\frac{n}{2}\rceil}^{n-1} i\log n\\ & \le\frac{n^2}{8}\log\frac{n}{2} + \frac{3n^2}{8}\log n\end{array}" />
  </p>
Replacing the sum by the final expression, we finally get 
<p align="center">
<img src="https://latex.codecogs.com/svg.image?P(n)&space;=&space;1&space;&plus;&space;4\log&space;n" title="P(n) = 1 + 4\log n" />
</p>
Therefore, the average case complexity of an operation on BST is of the order of <i>log n</i>

[Back to Index](../index.md)
