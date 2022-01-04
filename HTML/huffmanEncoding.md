## Application of Binary Trees

We learned in the last blog that a binary tree is a convenient data structure
for computing problems searching as elements are stored according to some 
sort of hierarchic relations. We will examine two specific examples where 
use of a binary tree as an underlying data structure eases the task of 
programming. 

The first example we deal with is the Huffman method of text compression. There
are more efficient methods for text compression, e.g., Lempel-Ziv (LZ)
algorithm. However, Huffman encoding simple, lossless, and optimal for 
static texts. The static text means that the text is known in advance. It also
implies that the alphabet set for the text is fixed. We can scan the text
to calculate the frequency of every symbol (alphabet) appearing in the input. 

It is possible encode a text using a fixed length code. In fixed code length
of each symbol in the text is fixed. For example, consider a text consisting
of eight symbols <i>a</i>, <i>b</i>, <i>c</i>, <i>d</i>, <i>e</i>, <i>f</i>
as shown in the table below. The freqeuncies of each symbols in the input 
text is provided in the first row of the table.  

<div align="center">
  
|                     | a  | b  | c  | d  | e  | f  |
| ------------------- |----|----|----|----|----|----|
| Freq. (in thousands)| 45 | 13 | 12 | 16 | 9  | 5  |
| Fixed length code   | 000| 001| 010| 011|100 |101 |
| Variable lengh code | 0  |101 |100 |111 |1101|1100|

</div>
Three-bit fixed-length code for each symbol is given in the second row of
the table. Decryption is fast and 
straightforward. We can repeatedly take out three bits from the encrypted
text prefix and retrieve the symbol that a 3-bit string represents by consulting 
the encoding table. 

Decryption process as stated above is characterized by the fact that 
encoding system satisfies <i>prefix property</i>. Formally, 

<strong >Prefix property</strong>: No code word is a prefix of any other codeword.  

Prefix property ensures no ambiguity in recovering a symbol 
from an encoded text by decoding the prefix that represents a valid symbol. 
So, the decryption process stated earlier should work. A fixed-length encoding uses <img src="https://latex.codecogs.com/svg.image?\log&space;\Sigma" title="\log \Sigma" /> bits for
each symbol, where <img src="https://latex.codecogs.com/svg.image?\Sigma" title="\Sigma" /> is the cardinality of the alphabet set. Therefore, no codeword
can be a prefix of any other codeword.

We explore whether a variable-length code can be found 
with prefix property. A variable-length code for the symbols is provided in
the third row of the above table. As we can observe, the variable-length 
code also satisfies the prefix property. So, it is also a prefix encoding.

Let us find out which of the two encodings is efficient. Since the text consist of
10<sup>5</sup> symbols, the fixed-length coding will require 3x10<sup>5</sup>
bits. However, the variable-length code will require 224000 bits. Therefore, the example indicates that
compressing a text with variable length code is more efficient than a fixed-length code. In the next blog, we plan to discuss the Huffman
encoding scheme and prove that it gives an optimal variable-length code.

[Back to Index](../index.md)
