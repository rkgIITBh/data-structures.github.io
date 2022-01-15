## Huffman Encoding is Optimal 

Optimality of Huffman encoding depends on showing that there is an optimal code in which the least frequent pair of alphabets are siblings. But 
getting into the details of the proof, let us understand the meaning of optimality. In the text compression problem, the focus is on minimizing the
number of bits required for representing a symbol with the constraints that decryption should be simple. Huffman encoding accomplishes both. Let <i>c</i>
be a character in the set of alphabets for the text. From Huffman tree the length of the code for <i>c</i> is equal to depth of leaf representing it.  
If frequency of <i>c</i> is <i>f(c)</i>, then the total number of bits consumed by all <i>c</i>s in the text is given by the expression <i>f(c)d<sub>T</sub>(c)</i>. Therefore, the total number of bits in the compressed text is: 
<p align="center">

</p>
Construction of Huffman code occurs bottom up. It start with the entire alphabet set <i>C</i>. If <i>c<sub>1</sub></i> and  <i>c<sub>2</sub></i> are
characters with least frequencies in the text, then both are combined to form one symbol <i>c'</i> of frequency <i>f(c<sub>1</sub>) + f(c<sub>2</sub>)</i>.
In the next step, the character set becomes:
<p align="center">

</p>
Huffman algorithm now tries to construct Huffman tree for above alphabet set  repeating the first step. It continues until the alphabet set reduces to having 
a single alphabet. The combined symbol at each step defines an internal node of the Huffman tree. The leaf nodes denote the initial alphabets of the text.

A Huffman tree provides us a prefix code. The code uses a 0 for a left branch in the tree, and a 1 for the right branch. If a prefix code is given, we 
can construct the underlying tree by a left branch for a 0, and
right branch for a 1. Therefore, in our arguments below, we may use prefix code and its tree interchangeably without raising any confusion. 

Let <i>X</i> represent all prefix codes for an alphabet set <i>A</i> where least frequent alphabets <i>a</i> and <i>b</i> are siblings. Similarly, let
<i>Y</i> represent all prefix codes for the alphabet set <i>A'</i>, where
<p align="center">

</p>
It essentially, means <i>a</i> and <i>b</i> are replaced by a new alphabet which combines both and the frequency of the new alphabet is the sum of 
frequencies <i>f(a)</i> and <i>f(b)</i>. 

<i>X</i> also contains an optimal code for <i>A</i> where <i>a</i> and <i>b</i> are siblings. Furthermore, for every tree in <i>X</i> there is a corresponding
tree in <i>Y</i>. Equivalently there exists an 1:1 correspondence between <i>X</i> and <i>Y</i>.

We define a base case for an alphabet set consisting of two alphabets. For the base case Huffman encoding creates an optimal code. Assume that it creates
optimal code for   . Therefore, using Huffman we can find an optimal code for
<i>A'</i>. From the above optimal code we replace the leaf node representing the combined alphabet    by  hanging <i>a</i> and <i>b</i> as children. 
Then the tree is a optimal tree in <i>X</i> with weight of an optimal tree in <i>Y</i> plus <i>f(a) + f(b)</i>
