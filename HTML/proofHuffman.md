## Huffman Encoding is Optimal 

The optimality of Huffman encoding depends on showing that there is an optimal code in which the least frequent pair of alphabets are siblings. 
Let us first understand the meaning of optimality. In the text compression problem, the focus is on minimizing the
number of bits required for representing a symbol with the constraints that decryption should be simple. Huffman encoding accomplishes both. Let <i>c</i>
be a character in the set of alphabets <i>A</i> for the text. From Huffman tree the length of the code for <i>c</i> is equal to depth of leaf representing it.  
If frequency of <i>c</i> is <i>f(c)</i>, then the total number of bits consumed by all <i>c</i>s in the text is given by the expression <i>f(c)d<sub>T</sub>(c)</i>. Therefore, the total number of bits in the compressed text is: 
<p align="center">
<img src="https://latex.codecogs.com/svg.image?\sum_{c\in&space;A}&space;f(c).d_T(c)" title="\sum_{c\in A} f(c).d_T(c)" />
</p>
Construction of Huffman code is bottom up. It starts with the entire alphabet set <i>A</i>. If <i>c<sub>1</sub></i> and  <i>c<sub>2</sub></i> are
characters with least frequencies in the text, then combines them to form one symbol <i>c'</i> of frequency <i>f(c<sub>1</sub>) + f(c<sub>2</sub>)</i>.
In the next step, the character set becomes:
<p align="center">
<img src="https://latex.codecogs.com/svg.image?A'&space;=&space;(A&space;-&space;\{a,&space;b\})\cup\{c\}" title="A' = (A - \{a, b\})\cup\{c\}" />
</p>
Huffman algorithm recursively constructs Huffman tree for the above alphabet until the alphabet set reduces to 
a single alphabet. The recursive step essentially, means <i>a</i> and <i>b</i> are replaced by a new alphabet <i>c</i> such that <i>f(c) = f(a) + f(b)</i>.
The combined symbol at each step defines an internal node of the Huffman tree. The leaf nodes denote the initial set of alphabets of the text.

A Huffman tree provides a prefix code. The code uses a 0 for a left branch in the tree, and a 1 for the right branch. Furthermore, beginning with a prefix code, 
it is possible to construct the underlying tree. Starting from the root, a 0 a left branch is taken for a 0, and
right branch for a 1. Therefore, in our arguments below, we may use prefix code and its tree interchangeably without raising any confusion. 

Let <i>X</i> consists of set of all trees that define prefix codes for alphabet set <i>A</i>. Therefore, <i>X</i> also contains an optimal code for <i>A</i> 
where <i>a</i> and <i>b</i> are siblings. Let <i>Y</i> be the set of all trees that define prefix codes for alphabet set <i>A'</i>.  For every tree in <i>X</i> 
there is a corresponding tree in <i>Y</i>. Equivalently there exists an <img src="https://latex.codecogs.com/svg.image?1\leftrightarrow&space;1" title="1\leftrightarrow 1" /> correspondence between <i>X</i> and <i>Y</i>.

We define a base case for an alphabet set consisting of two alphabets. It is obvious that Huffman encoding creates an optimal code base case. Now assume that
it creates optimal code for <img src="https://latex.codecogs.com/svg.image?|A|-1|" title="|A|-1|" />. From the optimal code for <img src="https://latex.codecogs.com/svg.image?|A|-1" title="|A|-1" /> we can create optimal code of <img src="https://latex.codecogs.com/svg.image?|A|" title="|A|" />  by  hanging <i>a</i> and <i>b</i> as children of <i>c</i>. 
Then the tree is a optimal tree in <i>X</i> with weight of an optimal tree in <i>Y</i> plus <i>f(a) + f(b)</i>.
