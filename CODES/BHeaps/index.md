## C Program for Binomial Heaps

```
// C++ program for implementation of
// Binomial Heap and Operations on it
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure of Node
typedef struct node {
	int info;
    int degree;
	struct node *parent;
    struct node *child;
    struct node *sibling;
} NODE;

// Making root global to avoid one extra
// parameter in all functions.
NODE * root = NULL;

// link two heaps by making h1 a child
// of h2.
int binomialLink(NODE* h1, NODE* h2) {
	h1->parent = h2;
	h1->sibling = h2->child;
	h2->child = h1;
	h2->degree = h2->degree + 1;
}

// create a Node
NODE* createNode(int n) {
	NODE* newNode = (NODE *) malloc(sizeof(NODE));
	newNode->info = n;
	newNode->parent = NULL;
	newNode->sibling = NULL;
	newNode->child = NULL;
	newNode->degree = 0;
	return newNode;
}

// This function merge two Binomial Trees
NODE* mergeHeaps(NODE* h1, NODE* h2) {
	if (h1 == NULL)
		return h2;
	if (h2 == NULL)
		return h1;

	// Define a Node
	NODE* res = NULL;

	// Check degree of which is smaller 
	if (h1->degree <= h2->degree)
		res = h1;

	else if (h1->degree > h2->degree)
		res = h2;

	// Traverse till if any of heaps becomes empty
	while (h1 != NULL && h2 != NULL) {
		// If degree of h1 is smaller, increment h1
		if (h1->degree < h2->degree)
			h1 = h1->sibling;

		// Link h1 with h2 in case of equal degree
		else if (h1->degree == h2->degree) {
			NODE* sib = h1->sibling;
			h1->sibling = h2;
			h1 = sib;
		}

		// If degree of h2 is greater
		else {
			NODE* sib = h2->sibling;
			h2->sibling = h1;
			h2 = sib;
		}
	}
	return res;
}

// Perform union on two binomial heaps
NODE* unionHeaps(NODE* h1, NODE* h2) {
	if (h1 == NULL && h2 == NULL)
		return NULL;

	NODE* res = mergeHeaps(h1, h2);

	// Traverse the merged list and set
	// values according to the degree of
	// nodes
	NODE *prev = NULL, *curr = res, *next = curr->sibling;
	while (next != NULL) {
		if ((curr->degree != next->degree)
			|| ((next->sibling != NULL)
				&& (next->sibling)->degree
					== curr->degree)) {
			prev = curr;
			curr = next;
		}

		else {
			if (curr->info <= next->info) {
				curr->sibling = next->sibling;
				binomialLink(next, curr);
			}
			else {
				if (prev == NULL)
					res = next;
				else
					prev->sibling = next;
				binomialLink(curr, next);
				curr = next;
			}
		}
		next = curr->sibling;
	}
	return res;
}

// Function to insert a Node
void binomialHeapInsert(int x) {
	// Create a new node and do union of
	// this node with root
	root = unionHeaps(root, createNode(x));
}

// Function to display the Nodes
void printHeap(NODE* h) {
	while (h) {
		printf("%d ", h->info);
		printHeap(h->child);
		h = h->sibling;
	}
}

// Function to reverse a list
// using recursion.
int revertList(NODE* h) {
	if (h->sibling != NULL) {
		revertList(h->sibling);
		(h->sibling)->sibling = h;
	}
	else
		root = h;
}

// Function to extract minimum value
NODE* deleteMin(NODE* h) {
	if (h == NULL)
		return NULL;

	NODE* minNodePred = NULL; // Predecessor node
	NODE* minNode = h;

	// Find minimum value
	int min = h->info;
	NODE* curr = h; // Current node
	while (curr->sibling != NULL) {
		if ((curr->sibling)->info < min) {
			min = (curr->sibling)->info;
			minNodePred = curr;
			minNode = curr->sibling;
		}
		curr = curr->sibling;
	}

	// If there is a single Node
	if (minNodePred == NULL && minNode->sibling == NULL)
		h = NULL;

	else if (minNodePred == NULL)
		h = minNode->sibling;

	// Remove min node from list
	else
		minNodePred->sibling = minNode->sibling;

	// Set root (which is global) as children
	// list of min node
	if (minNode->child != NULL) {
		revertList(minNode->child);
		(minNode->child)->sibling = NULL;
	}

	// Do union of root h and children
	return unionHeaps(h, root);
}

// Function to search for an element
NODE* findNode(NODE* h, int val) {

    // Return NULL if the heap is empty
	if (h == NULL)
		return NULL;

	// Retrun root if key is equal to the root's data
	if (h->info == val)
		return h;

	// Check the child recursively 
	NODE* res = findNode(h->child, val);
	if (res != NULL)
		return res;

	return findNode(h->sibling, val);
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

// Decrease the value of key 
void decreaseKey(NODE* H, int oldVal, int newVal) {
    
	// Check if element is present or not
	NODE* node = findNode(H, oldVal);

	// Return if Node is not present
	if (node == NULL)
		return;

	// Reduce the value to the minimum
	node->info = newVal;
	NODE* parent = node->parent;

	// Update the heap according to reduced value
	while (parent != NULL && node->info < parent->info) {
		swap(&node->info, &parent->info);
		node = parent;
		parent = parent->parent;
	}
}

// Function to delete an element
NODE* binomialHeapDelete(NODE* h, int val) {
	// Retrun if the heap is empty
	if (h == NULL)
		return NULL;

	// Reduce the value of element to minimum
	decreaseKey(h, val, INT_MIN);

	// Delete the minimum element from heap
	return deleteMin(h);
}
// Create main() for experimenting with operations
```

[Back to Binomial Heaps](../../HTML/binomialHeaps.md)
