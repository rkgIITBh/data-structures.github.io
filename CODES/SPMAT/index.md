## Source Code for Sparse Matrix Representation

```
#include <stdlib.h>
#include <stdio.h>
#define MAX1 4 // row dimension
#define MAX2 4 // column dimension

// Structure to store element 
typedef struct Node { // Structure for nonzero element
    int row;
    int col;
    int val;
    struct Node* right;
    struct Node* down;
} ENTRY;

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

void initSparse(SPARSE *);
void createArray(SPARSE *);
void printMatrix(SPARSE);
int  count(SPARSE);
void createTriplet(SPARSE*, SPARSE);
void createLinkedList(SPARSE *);
void insert(SPARSE *, SPMAT *, int, int, int);
void printLinkedList(SPARSE);
void delSparse(SPARSE *);

void main() {
    SPARSE s1, s2;

    initSparse(&s1);
    initSparse(&s2);

    createArray(&s1);

    printf("\nElements in sparse matrix: ");
    printMatrix(s1);

    createTriplet(&s2, s1);

    createLinkedList(&s2);
    printf("\n\nInformation stored in linked list :\n");
    printLinkedList(s2);

    delSparse(&s1);
    delSparse(&s2);

}

// Initialize the fields of different structures
void initSparse(SPARSE * p) {
    int i;
    // Create row headnodes
    for (i = 0; i < MAX1; i++)
        p->rhead[i] = (struct rHead*)malloc(sizeof(struct rHead));

    // Initialize and link row headnodes 
    for (i = 0; i < MAX1 - 1; i++) {
        p->rhead[i]->next = p->rhead[i + 1];
        p->rhead[i]->right = NULL;
        p->rhead[i]->rowno = i;
    }
    p->rhead[i]->right = NULL;
    p->rhead[i]->next = NULL;

    // Create col headnodes 
    for (i = 0; i < MAX1; i++)
        p->cHead[i] = (struct cHead*)malloc(sizeof(struct cHead));

    // Initialize and link col headnodes 
    for (i = 0; i < MAX2 - 1; i++) {
        p->cHead[i]->next = (struct cHead*)p->cHead[i + 1];
        p->cHead[i]->down = NULL;
        p->cHead[i]->colno = i;
    }
    p->cHead[i]->down = NULL;
    p->cHead[i]->next = NULL;

    // Create and initialize special headnode
    p->smat = (struct spmat*)malloc(sizeof(struct spmat));
    p->smat->firstCol = p->cHead[0];
    p->smat->firstRow = p->rhead[0];
    p->smat->nCols = MAX2; // No of columns
    p->smat->nRows = MAX1; // No of row
}

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

// Print the matrix
void printMatrix(SPARSE s) {
    int i;

    // Print nonzero elements of the matrix
    for (i = 0; i < MAX1 * MAX2; i++) {
        // Position the cursor at a new line for every new row 
        if (i % MAX2 == 0)
            printf("\n");
        printf("%d\t", *(s.sp + i));
    }
}

// Counts the number of non-zero elements 
int count(SPARSE s) {
    int cnt = 0, i;

    for (i = 0; i < MAX1 * MAX2; i++) {
        if (*(s.sp + i) != 0)
            cnt++;
    }
    return cnt;
}

// Creates an array of triplet for non-zero elements
void createTriplet(SPARSE * p, SPARSE s) {
    int r = 0, c = -1, l = -1, i;

    p->row = count(s);
    p->sp = (int*)malloc(p->row * 3 * sizeof(int));

    for (i = 0; i < MAX1 * MAX2; i++) {
        c++;
        // sets the row and column values 
        if (((i % MAX2) == 0) && (i != 0)) {
            r++;
            c = 0;
        }

        // Checks for non-zero element. Row, column and
        // non-zero element value is assigned to the matrix
        if (*(s.sp + i) != 0) {
            l++;
            *(p->sp + l++) = r; // Store row no
            *(p->sp + l++) = c; // Store col no
            *(p->sp + l) = *(s.sp + i); // Store value
        }
    }
}

// Information of triplet stored in a linked list 
void createLinkedList(SPARSE * p) {
    int j = 0, i;
    for (i = 0; i < p->row; i++, j += 3)
        insert(p, p->smat, *(p->sp + j), *(p->sp + j + 1), *(p->sp + j + 2));
}

// Inserts element to the list 
void insert(SPARSE * p, SPMAT * smat, int r, int c, int v) {
    struct Node* p1=NULL, * p2=NULL;
    struct rHead* rh;
    struct cHead* ch;
    int i, j;

    // Allocate and initialize memory for the node
    p->nd = (struct Node*)malloc(sizeof(struct Node));
    p->nd->col = c;
    p->nd->row = r;
    p->nd->val = v;

    // Get the first row headnode
    rh = smat->firstRow;

    // Get the row headnode r
    for (i = 0; i < r; i++)
        rh = rh->next;
    p1 = rh->right; 

    // If no nonzero element yet in row r
    if (p1 == NULL) {
        rh->right = p->nd;
        p->nd->right = NULL;
    }
    else {
        // Go to correct column position 
        while ((p1 != NULL) && (p1->col < c)) {
            p2 = p1;
            p1 = p1->right;
        }
        p2->right = p->nd;
        p->nd->right = NULL;
    }

    // Link the element with col headnode for column c 
    ch = p->smat->firstCol;
    for (j = 0; j < c; j++)
        ch = (struct cHead*)ch->next;
    p1 = ch->down;

    // No nonzero element yet in col c
    if (p1 == NULL) {
        ch->down = p->nd;
        p->nd->down = NULL;
    }
    else {
        // Link previous nonzero element in column c
        // with next element in column c 
        while ((p1 != NULL) && (p1->row < r)) {
            p2 = p1;
            p1 = p1->down;
        }
        p2->down = p->nd;
        p->nd->down = NULL;
    }
}

void printLinkedList(SPARSE s) {
    struct Node* p;
    // Get the first row headnode 
    int r = s.smat->nRows;
    int i;

    for (i = 0; i < r; i++) {
        p = s.rhead[i]->right;
        if (p != NULL) {
            while (p->right != NULL) {
                printf("\nRow: %d Col: %d Val: %d\n", p->row, p->col, p->val);
                p = p->right;
            }
            if (p->row == i)
                printf("Row: %d Col: %d Val: %d\n", p->row, p->col, p->val);
        }
    }
}

// Deallocate memory
void delSparse(SPARSE * p) {
    int r = p->smat->nRows;
    struct rHead* rh;
    struct Node* p1, * p2;
    int i, c;

    // Deallocate memeory of nodes by traversing row-wise
    for (i = r - 1; i >= 0; i--) {
        rh = p->rhead[i];
        p1 = rh->right;
        while (p1 != NULL) {
            p2 = p1->right;
            free(p1);
            p1 = p2;
        }
    }

    // Deallocate memory of row headnodes 
    for (i = r - 1; i >= 0; i--)
        free(p->rhead[i]);

    // Deallocate memory of col headnodes 
    c = p->smat->nCols;
    for (i = c - 1; i >= 0; i--)
        free(p->cHead[i]);
}
```

[Back to Sparsematrix](../../HTML/sparseMatrix.md)
