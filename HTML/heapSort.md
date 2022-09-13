## Heap Sort

Heapsort is a comparison-based algorithm. It essentially allows us to select minimum element
in O(1) time after the heap is built. However, deletion of the minimum spoils the heap property.
So, the after deletion, we must perform heapify operation to restore the heap property for the
remaining element. Heapify operation takes O(log <i>n</i>) time. Therefore, the running time of
heapsort is O(<i>n</i>log <i>n</i>). We have studied binary heaps in connection with priority
queues. To refresh our memory let us reexamine the process of building heap from a set of
given elements from an ordered set.

<strong>Heap property</strong>

A heap is a complete binary tree such that the value stored in the node is smaller than or equal 
to that stored at any of its children nodes.

The following tree represents a binary heap.
<p style="text-align:center">
  <img src="../images/binaryHeap.jpg">
</p>
The parent of a node at position <i>i</i> is available in the index postion &lceil;<i>i</i>&rceil;-1.

Building heap is simple. We take one element at a time and build the heap by applying heapify 
operation. The first element defines a heap of one element. Suppose a heap of a few elements 
is already available. The new element joins the heap at the leftmost vacant position in the 
highest level of the binary tree. It ensure the structural property of the heap remains unchanged.
After creating a new node for an incoming element, we apply a heapify operation along the tree
path from the new node bottom up which is sometimes known as shiftup. It takes time of 
O(log <i>n</i>) to restore the heap property along the path. 
