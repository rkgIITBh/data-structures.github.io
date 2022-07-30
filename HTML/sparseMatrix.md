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
  <img src="../images/matrixNodeStr.png"><br>
  Figure 1
</p>

Using the node structures as explained above, we can store a sparse matrix as depicted below:
<p style="text-aling:center">
  <img src="../images/matrixEx1.png"><br>
  Figure 2
</p>

We also need a unified node structure which is used for understanding organization of matrix nodes corresponding
to a sparse matrix. The structure of this node is explained in the diagram below.
<p style="text-aling:center">
  <img src="../images/sparseMatrixStr.png"><br>
  Figure 3
</p>
Let us now explore how each node structure is represented by a C-structure. First we need to define
the total number of non=zero elements. We denote the dimensions by two constants <i>MAX1</i> and 
<i>MAX2</i>. An entry node has two pointers and a triplet that defines the non-zero element's row_no,
col_no and the value. So, the C-structure corresponding to an entry node is as follows:
```
#define MAX1 4 // row dimension
#define MAX2 4 // column dimension

// Structure to store a non-zero element 
typedef struct Node { 
    int row; // row number
    int col; // col number
    int val; // Value of the entry
    struct Node* right; // Ptr to next element in the same row
    struct Node* down;  // Ptr to next element in the same col
} ENTRY;
```
The next two node structures are for column and row headers. Each such structure has one information and 
two pointers. The column header should store the column number and points to next header node and 
the next element in the same column. Similarly, a row header stores the row number and pointers to 
next element in same row and the next row header. The next row header pointer is denoted as <i>down</i>. 
```
// Structure for column headnode 
typedef struct cHead {
    int colno;
    ENTRY * down;
    struct cHead* next;
} CHEAD;

// Structure for row headnode 
typedef struct rHead {
    int rowno;
    ENTRY * right;
    struct rHead* next;
} RHEAD;
```

```

// Structure for matrix headnode
typedef struct spmat {
    RHEAD * firstRow;
    CHEAD * firstCol;
    int nRows;
    int nCols;
} SPMAT;

// Use for accessing whole of sparse matrix including
// all elements which allows us to also build triplets 
typedef struct sparse {
    int* sp; // Storage for all elements
    int row; // Number of nonzero elements in matrix
    SPMAT * smat;
    CHEAD * cHead[MAX2];
    RHEAD * rhead[MAX1];
    ENTRY * nd;
} SPARSE;


```

Each non-zero element is a triplet of the form (row_no, col_no, value). Let <i>nonZero</i> be the number of non-zero
elements, and <i>mn</i> is the dimension of the matrix. Then the ratio of <i>mn-nonZero</i> and <i>mn</i>
defines the sparsity of matrix. If sparsity exceeds 0.5 then the matrix is sparse. The sparse matrix shown in
the Figure 3 has only four non-zero elements. Therefore the sparsity of the matrix = 0.75. 

We can create sparse matrix by creating a entry node for each non-zero element. The entry node is placed in 
position corresponding to its row and column number. The code for creating entry node is given below.
```
// Create an array MAX1 x Max2 for matrix 
void createArray(SPARSE * p) {
    int n, i;

    p->sp = (int*)malloc(MAX1 * MAX2 * sizeof(int));

    // Read values and store in array 
    for (i = 0; i < MAX1 * MAX2; i++) {
        printf("Enter element no. %d:", i);
        scanf("%d", &n);
        *(p->sp + i) = n;
    }
}
```


  . The sparsity is checked to 
