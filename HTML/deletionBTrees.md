## B-Tree Deletion Operation 
 
Suppose we want to delete a key <i>k</i> from a node <i>n</i>. If <i>n</i> is not in a leaf 
then we can replace <i>k</i> by the largest key <i>k<sub>L</sub></i> in the left subtree under node <i>n</i>. The key 
<i>k<sub>L</sub></i> would occur in a leaf node. The deletion process is essentially a generalization of the deletion in 
BST. Therefore, all deletions occur in leaf nodes. It may lead to an underflow. An underflow occurs when the number of
keys in a leaf node is reduced to <i>M/2 - 1</i>. If the sibling node has surplus keys to share, keys can be moved to
the deficient node and restore the requirement of B-Tree. However, if the sibling has just <i>M/2</i> keys we have 
merge the two siblings into one node. Merging may percolate up and require merging at a level up. When children of the 
root merge together to form one node a new root is created which decrements the height by 1. Thus repeated deletions 
may lead to a reduction in tree height.
 
```
deleteKey(k, r) {
    n = searchKey(k, r);
    if(!isLeaf(n)) {
         delete k from n;
         find the immediately largest key k1;
         // k1 is guaranteed to be on a leaf node l
         copy k1 in the old position k;
         deleteKey(k1, l);
    else {
        // n is a leaf node */
        if(isUnderflow(n)){
             // Let n1 be the sibling of n;
             if( isRich(n1)){ 
L:                // A key can be borrow from n1
                  borrow a key from n1 via the parent node p;
             } else{ 
                  // n1 is 1 key away from underflowing 
                  // pull the key from the parent ’p’, and merge it
                  // with the keys of ’n’ and ’n1’ into a new node
                  mergeNodes(n, n1); 
                  if( isUnderflow(p)) 
                       repeat from L;
             }
   }
... 

Before we describe the node structures, it is important to know about amortized cost.


