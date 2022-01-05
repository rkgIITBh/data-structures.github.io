## C Source Code for Huffman Encoding Scheme

```
#ifndef HUFFMAN_H
#define HUFFMAN_H
#define MAXHEIGHT 50

// Define tree node
typedef struct node {
  char symbol;
  int freq;
  struct node *left, *right;
} HNODE;   

// Define heap which store codes 
typedef struct minHeap {
  int size;
  int capacity;
  HNODE **array; 
} MHEAP;   

// Function for creating a new node
HNODE *newNode(char symbol, int freq) {
    HNODE *p = (HNODE *) malloc(sizeof(HNODE));

    if (p == NULL) {
        printf("Failure: memory allocation\n"); 
        return NULL;
    }
    // Create node, if allocation is successful 
    p->left = p->right = NULL;
    p->symbol = symbol;
    p->freq = freq;

    return p;
}

// Function for creating min heap of given capacity
MHEAP *createHeap(int capacity) {
    MHEAP *h = (MHEAP *)malloc(sizeof(MHEAP));

    h->size = 0;
    h->capacity = capacity;
    h->array = (HNODE **) malloc(h->capacity * sizeof(HNODE *));
    return h;
}

// Swap the heap nodes for heapify operation 
void swapHNODE(HNODE **a, HNODE **b) {
    HNODE *t = *a;

    *a = *b;
    *b = t;
}

// Heapify operation 
void heapify(MHEAP *h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < h->size && h->array[left]->freq < h->array[smallest]->freq)
        smallest = left;

    if (right < h->size && h->array[right]->freq < h->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapHNODE(&h->array[smallest], &h->array[idx]);
        heapify(h, smallest);
    }
}

// Check if size if 1
int checkSizeOne(MHEAP *h) {
    // Heap size 1 implies a leaf
    return (h->size == 1); 
}

// Extract min
HNODE *deleteMin(MHEAP *h) {

     HNODE *p = h->array[0]; // Get minimum
     
     // Copy last node to first node
     h->array[0] = h->array[h->size - 1]; 
     --h->size; // Reduce the heap size 
     heapify(h, 0); // Restore heap property 

     return p; // Return after deletion
}

// Insertion function
void insertHeap(MHEAP *h, HNODE *hNode) {
     ++h->size; // Increment heap size
     int i = h->size - 1; // Index of the blank last element.

     while (i && hNode->freq < h->array[(i - 1) / 2]->freq) {
         // If new node's frequency < parent's frequency
         // push the parent down to  and climb up
          h->array[i] = h->array[(i - 1) / 2]; 
          i = (i - 1) / 2; // Climb up
     }
     // Correct positon of new node found
     h->array[i] = hNode; 
}

void buildHeap(MHEAP *h) {
     int n = h->size - 1;
     int i;

     for (i = (n - 1) / 2; i >= 0; --i)
          heapify(h, i);
}

int isLeaf(HNODE *root) {
    return !(root->left) && !(root->right);
}

MHEAP *createAndBuildHeap(char symbol[], int freq[], int size) {
    MHEAP *h = createHeap(size);

    for (int i = 0; i < size; ++i)
        h->array[i] = newNode(symbol[i], freq[i]);

    h->size = size;
    buildHeap(h);

    return h;
}

HNODE *buildHuffmanTree(char symbol[], int freq[], int size) {
     HNODE *left, *right, *top;

     // Create heap of frequencies associated with symbols
     MHEAP *h = createAndBuildHeap(symbol, freq, size);

     while (!checkSizeOne(h)) {
          // Get a pair of least frequency nodes
          left = deleteMin(h); 
          right = deleteMin(h);

          // Use '$' as meta symbol 
          top = newNode('$', left->freq + right->freq);

          top->left = left;
          top->right = right;

          insertHeap(h, top); // Insert meta symbol
     }
     return deleteMin(h); // Returns last meta symbol
}

// Print the array
void printArray(int arr[], int n) {
     int i;

     for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
     printf("\n");
}

// Print the codes
void printHCodes(HNODE *root, int arr[], int top) {
     if (root->left) {
        arr[top] = 0; // Add 0 for left branch 
        printHCodes(root->left, arr, top + 1);
     }
     if (root->right) {
        arr[top] = 1; // Add 1 for right branch
        printHCodes(root->right, arr, top + 1);
     }
     // If a leaf is reached print the code
     if (isLeaf(root)) {
        printf("    %c    |  ", root->symbol);
        printArray(arr, top);
     }
}

// Wrapper function for printing Huffman code
void HuffmanCodes(char symbol[], int freq[], int size) {
     int arr[MAXHEIGHT];
     int top = 0;
     
     // Build Huffman tree for give symbol set and 
     // corresponding symbol frequencies
     HNODE *root = buildHuffmanTree(symbol, freq, size);

     printHCodes(root, arr, top);
}
#endif
```

[Back to Index](../../index.md)
