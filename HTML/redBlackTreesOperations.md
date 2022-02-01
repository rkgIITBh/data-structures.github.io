## Operations on Red-Black Trees

The insertion of a new node takes place at the site of an external node, and two new external nodes are added as children of the new node. So, if we color 
it black then the black height of the tree increases and height invariant is violated. More explicitly, the black depth of the tree path from the root to 
the newly inserted node increase, but black depth of paths from the root to other external nodes are unchanged.  An insertion into a red-black tree shoud
preserves height invariant, order invariant and two other color properties except the invariant requiring no two consecutive nodes can have red colors. 
How do we flip the color of a node from red to black or vice versa?

<strong>Color flipping rule</strong>: Suppose <i>K</i> is the new node, and its uncle <i>U</i> is red. If <i>P</i> is the left child of its parent <i>G</i>,then

- Transfer the color of <i>G</i> to <i>P</i> and its sibling <i>U</i>
- Recolor <i>G</i> to red.

Since <i>P</i>'s color is red, <i>G</i> must be black. Transfering color of <i>G</i> to <i>U</i> and <i>P</i> does not violate height invariant. Only it
pushes the color problem to <i>G</i> and the parent of <i>G</i>.

However, if <i>U</i> is black then problem is complicated. Four restructuring rules are rotations, namely, (i) Right, (ii) Left, (iii) Right-Left and 
(iv) Left-Right. We have seen these restructuring earlier in connection with AVL trees.
