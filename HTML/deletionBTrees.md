<strong>Deletion:</strong> Suppose we want to delete a key <i>k</i> from a node <i>n</i>. If <i>n</i> is not in a leaf 
then we can replace <i>k</i> by the largest key <i>k<sub>L</sub> in the left subtree under node <i>n</i>. The key 
<i>k<sub>L</sub> would occur in a leaf node. The deletion process is essentially a generalization of the deletion in 
BST. Therefore, all deletions occur in leaf nodes. It may lead to an underflow. An underflow occurs when the number of
keys in a leaf node is reduced to <i>M/2 - 1</i>. If the sibling node has surplus keys to share, keys can be moved to
the deficient node and restore the requirement of B-Tree. However, if the sibling has just <i>M/2</i> keys we have 
merge the two siblings into one node. Merging may percolate up and require merging at a level up. When children of the 
root merge together to form one node a new root is created which decrements the height by 1. Thus repeated deletions 
may lead to a reduction in tree height.
 
```
DELETION OF KEY ’K’
search for key k in node n;
if(!isLeaf(n)) {
    delete k from n;
    find the immediately largest key k1;
    /* which is guaranteed to be on a leaf node ’L’ */
    copy k1 in the old position k;
    deleteKey(k1, l);
else {
     /* ’N’ is a leaf node */
    if( isUnderflow(n)){
        // Let n1 be the sibling of n;
        if( isRich(n1)){ 
            /* A key can be borrowd from n1
            borrow a key from n1 THROUGH the parent node p;
        } else{ 
             /* N1 is 1 key away from underflowing */
             MERGE(n, n1, n2); // pull the key from the parent ’P’,
and merge it with the keys of ’N’ and ’N1’ into a new
node;
if( isUnderflow(p) 
        underflows){ repeat recursively }
}
}
 
... 


```
 
Before we describe the node structures, it is important to know about amortized cost.

<strong>Amortized cost:</strong> is defined over a sequence or a set of operations. If some operations of a given set are 
costly because future operations become cheap, we say time is amortized over the given set of operations. We have learned 
about amortized cost earlier in the context of <b>union</b> and <b>find</b> instructions on disjoint sets. The reader 
might remember that a sequence of O(<i>n</i>) unions and finds can be executed in O(<i>nG(n</i>)) time where <i>G(n)</i>
is an extremely slow-growing function. So, for all practical purpose, each operation of sequence take O(1) amortized
time. Loosely speaking, amortized time is time partitioned over many operations. We will return to amortized time in 
the analysis of B-Tree at a later point.

