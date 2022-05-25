## Introduction to B-Trees

B-Trees are used to store very large dictionaries B-Trees allow searches, insertions, and deletions in amortized 
logarithmic time.  A B-Tree node may have up to a few thousand nodes. Since B-Trees have very high branching 
factor, the tree tend to be bushy compared to red-black tree. It does not require rebalancing operations like rotations.
But as more and more insertions happen, the nodes cannot accommodate them. So, nodes must be added to handle insertions.
On the other hand, when deletions take place, it leads to wastage of storage space. To handle both situations, B-Tree
nodes are restructured by splitting and merging. Splitting of a node occurs more and more keys accumulate for room 
at the node. Similarly, merging occurs when a pair of sibling nodes have lot of vacancies for keys due repeated 
deletions. Merging reduces height as it may propagate up to the root of tree. Splitting also propagate all the way to
the root of a tree causing its height to increase. 


<strong>Defining a B-Tree</strong>

We formalize the definition of a B-Tree specifying the following properties.

- The root is a special node that may have between 2 and <i>M</i> children. 
- An internal node may have between <i>M/2</i> and <i>M</i> children.
- The number of keys stored at a node is one less than the number of children.  
- Each leaf node is at the same depth from the root.
- A leaf node stores at most <i>M-1</i> and at least <i>M/2</i> elements in sorted order. 

The root is the only node in a B-Tree that may be less than half full.

B-Trees do not require rebalancing operations like rotations. But they need nodes to split and merge to handle dynamicity
of key insertions and deletions. Insertions increase the number of stored elements and may require splits. Splits may 
propagate up to the root, causing the tree's height to increase. On the other hand, the merging of nodes occurs with 
deletions. It may cause the height of a B-Tree to decrease. The elements appear in sorted order at nodes. 

The figure below gives the picture of a B-Tree with <i>M=4</i>. 

<p style="text-align:center;"><img src="../images/bTreeEx1.png"></p>

In the figure, the root has two elements: 20 and 40.
- The elements less than 20 can be reached following the leftmost pointer. 
- The elements between the range (20, 40) are reachable from the pointer to the right of 20. 
- The elements greater than 40 are reachable from the pointer to the right of 40. 

Loosely speaking, the two adjacent numbers <i>a</i>, <i>b</i> in an internal node represent an open interval <i>(a, b)</i>. 
Any number <i>x</i> in <i>(a, b)</i>, if it exists in the tree, may be found in one of the descendant node <i>u</i> of 
<i>v</i> which is accessible from the pointer between the numbers <i>a</i> and  <i>b</i>.  

The minmum number of keys in a tree of height 1 is 1. If we increase height of the tree by 1, the minimum number of keys 
increases by <i>2k - 1</i>, where <i>k</i>=&lceil;<i>M/2</i>&rceil;. So for different heights of the tree in the minimum 
number of nodes is: 
 

| Height | Number of keys | 
| -------- | -------|   
|   1    | 1 |
|   2    | 1+2<i>(k-1)</i>|
|   3    | 1+2<i>(k-1)</i>+2<i>(k-1)k</i>|
|   4    | 1+2<i>(k-1)(1+k+k<sup>2</sup>)</i>|



In general if height is <i>h</i> then the minimum number of keys will be:

<p style="text-align:center;">
<i>2(k-1)(1+k+k<sup>2</sup> + k<sup>3</sup> + ... + k<sup>h</sup>)</i>
</p>
Therefore, for a B-Tree with <i>n</i> nodes the height should be at most 1 + log<i><sub>k</sub></i>((1+<i>n</i>)/2)
<br><br>
In the above example, we do not distinguish between items and their keys. Equivalently, an item and its key are are the same. 
However, typically in real database implementation, a distinction exists between items and their corresponding keys. 
Items are records accessed by providing corresponding primary keys. Therefore, we have two ways of storing items in B-Tree. 

1. Keys are stored at nodes, and items are stored at external nodes. 
2. A key and its corresponding item are stored together at the same position.  

Using different keys and items, we can modify the above example to store data at external nodes, as shown below. 

<p style="text-align:center;"><img src="../images/bTreeEx2.png"></p>

<strong>Search:</strong> Search operation in a B-Tree is a generalization of the binary search. It combines advantage of a
binary search tree with plain binary search on a sorted list. For convenience in description we use the following notation:
- <i>k</i>: key value for search
- <i>n</i>: Current node

The search typically start from root. We try to find a match for <i>k</i> in the local cache of keys maintained at the
current node <i>n</i>. If a match is found then we return the node and the index of the matched key. If no match is found
in local key cache and <i>n</i> is a leaf, the search terminates without a match for <i>k</i>. Otherwise, we use the left 
child pointer of the smallest key greater than <i>k</i> in the current node, and recursively perform search from the
left child. The pseudo code for searching a <i>k</i> in a given B-Tree appears below.

```
BtreeSearch(n, k) {
     i = 1;   // Start from first key position
     while (i <= n.count and k >= n.key[i])   //n.count gives the number of keys in node n
           i = i + 1;  // Locate the smallest key greater than k
     if (i <= n.count and k == n.key[i]) // n.key[i] matches k
           return (n, i); 
     if (isLeaf(n))
           return NIL   // If current node is leaf then key is absent
     else 
          // Recursively search the child node from the pointer to the left of n.key[i]
           return BtreeSearch(n.child, k);
}
```

<strong>Insertion:</strong> Fort inserting a node, perform a search for the key in the given B-Tree. If element is not found 
the search will terminate at a leaf. If the leaf contains less than <i>M-1</i> keys then insert the key there. It will 
require data movements. Some keys may have to be moved to right to make room for the new insertion. If the leaf is full
(i.e., it contains <i>M-1</i> keys) then create a new leaf. Retain the first half the keys in the old leaf and move the
second half of the keys to newly created leaf. Push the median to parent and create an extra child link for the new leaf 
to right of median key pushed to the parent. If parent does not have room, repeat the splitting process again at the parent. 
The recursice process of splitting may finally the root and increase the height of the tree.

More formally, the step-wise process of insertion is as follows:

1. Start at the root node and search for the key <i>k</i> to find the place where it can be pushed. Call the node as <i>N</i>.
2. If <i>N</i> has room shift larger element to right, place <i>k</i>, and terminate.  
3. Otherwise, <i>N</i> is full, split it two nodes:
   - Retain the smaller half the keys in the original node 
   - Move the larger half of keys to the newly create node.
   - Choose the median of the keys and push it to the parent of original leaf. 
   - If parent is full, it may necessitate a split of parent and split may percolate recursively to root. 
 4. Split the root if required and terminate.
 
Splitting of the root creates a new root and increase the height of the tree. However, unlike balanced trees, B-Tree does
not use rotations to fixiup or rebalancing the tree. 

<strong>Deletion:</strong> If the element <i>x</i> for deletion is not located in a leaf then we can replace <i>x</i> by
the largest element <i>y</i> in the left subtree of <i>x</i>. The key <i>y</i> must be located in a leaf node. So, the 
deletion process is essentially a generalization of the deletion in BST. All deletions occur in leaf nodes. It may lead to
an underflow. An underflow occurs when the number of keys in a leaf node is reduced to <i>M/2 - 1</i>. If the sibling 
node has surplus keys to share, keys can be moved to deficient node and restore the requirement of B-Tree. However, if 
the sibling has just <i>M/2</i> keys we can merge the two siblings to form one node. Merging may percolate up and 
require merging at a level up. When children of the root merge together to form one node a new root is created which
decrements the height by 1. Thus repeated deletions may lead to a reduction in tree height.
 
 
 
 
 
 
Before we describe the node structures, it is important to know about amortized cost.
<strong>Amortized cost:</strong> is defined over a sequence or a set of operations. If some operations of a given set are 
costly because future operations become cheap, we say time is amortized over the given set of operations. We have learned 
about amortized cost earlier in the context of <b>union</b> and <b>find</b> instructions on disjoint sets. The reader 
might remember that a sequence of O(<i>n</i>) unions and finds can be executed in O(<i>nG(n</i>)) time where <i>G(n)</i>
is an extremely slow-growing function. So, for all practical purpose, each operation of sequence take O(1) amortized
time. Loosely speaking, amortized time is time partitioned over many operations. We will return to amortized time in 
the analysis of B-Tree at a later point.

