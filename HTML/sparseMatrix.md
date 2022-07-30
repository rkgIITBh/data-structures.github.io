## Sparse Matrix

A sparse matrix of dimension <i>m</i>x<i>n</i> consists of fewer than <i>mn/2</i> non-zero elements. That is
it has more zero than nonzero elements. When operating with multiple sparse matrix of high dimensionality, 
storing and operating on them become chanllenging. The major problem lies in storing the sparse matrices. We
require a bit of careful organization taking advantage of the fact that it has many zero elements. While 
investigating linke lists, we noticed that in these data structures, each element can store references of 
sequentially next element in the list. We can also use multiple link pointers with each node a linked list
to associate it with different sequential lists. Examining the structure and operations on matrices, one may
realize that each matrix entry can be associated with four other entries to the left, right, top and the 
bottom. Therefore, we use linked lists to store a sparse matrix. The figure below depicts the relation of 
an entry with other neighboring entries in a sparse matrix.
<p style="text-aling:center">
  <img src="../images/sparseNodeStructure.png">
  </p>
