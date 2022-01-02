## Application of Binary Trees

We learned in the last blog that binary tree is a convenient data structures
for computing problems searching as elements ared stored according to some 
sort of hierarchic relations. We will examine two specific examples where 
use of binary tree as an underlying data structure eases the task of 
programming. 

The first example we deal with is Huffman method of text compression. There
are more efficient methods for text compression, e.g., Lempel-Ziv (LZ)
algorithm. However, Huffman encoding simple, lossless and optimal for 
static texts. Static text means that the text is known in advance. It also
implies that the alphabet set for the text is fixed. We can scan the text
to calculate the frequency of every symbol (alphabet) appearing in the input. 

It is possible encode a text using a fixed length code. In fixed code length
of each symbol in the text is fixed. For example, consider a text consisting
of eight symbols as shown in the figure below. 
<p align="center">
  <img src="../images/fixedLengthCode.jpg">
</p>
Three-bit encoding will suffice for such a text. Decryption is fast and 
simple. We can repeatedly take out three bits from the prefix of encrypted
text, and retrieve the symbol that a 3-bit string represents by consulting 
the encoding table. 

Decryption process as stated above is characterized by the fact that 
encoding system satisfies <i>prefix property</i>. Formally, 

<strong >Prefix property</strong>: No code word is a prefix of any other codeword.  

Prefix property ensures that there is no ambiguity in recovering a symbol 
from encoded text by decoding the prefix that represents a valid symbol. 
So, the decryption process stated earlier should work. The fixed length 
code as illustrate in the figure above satisfies prefix property. 

Now, we explore the question whether a variable length code can be found 
with prefix property.  


 
