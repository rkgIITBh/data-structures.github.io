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
  <img src="../images/sparseMatNbrs.png">
</p>
The picture indicates that we can creat a node structure which lets each entry of a sparse matrix to be a
part of at least two linked lists:

- a linked list of entries in single column
- a linked list of entries in single row

Therefore, we need a node structure for matrix entries having two link pointers. Since we do not store zero
elements physically, the row and col of the entry must be available with the value of the entry. So, the 
node structure for a matrix entry must have five fields:

- The value of the entry, row and column number to which the entry belongs.
- Pointers to next entry in same row and next entry in same column.

We also need a header nodes for each column and a header node for each row. The header node for a column should
take us to the first non-zero entry in the column. In addition it should be able to take us to the next column
header. Similar structure is also needed to a row header. Finally, we need a header node for the entire matrix.
It should be able to point to first column and first row headers. So, we have  four different node structures as
shown in the figure below:
<p style="text-aling:center">
  <img src="../images/matrixNodeStr.png">
</p>

Using the node structures as explained above, we can store a sparse matrix as depicted below:
<p style="text-aling:center">
  <img src="../images/matrixEx1.png">
</p>

