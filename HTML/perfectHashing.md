## Perfect Hashing

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML"> </script> <script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: { inlineMath: [['$','$'], ['\\(','\\)']], processEscapes: true}, jax: ["input/TeX","input/MathML","input/AsciiMath","output/CommonHTML"], extensions: ["tex2jax.js","mml2jax.js","asciimath2jax.js","MathMenu.js","MathZoom.js","AssistiveMML.js", "[Contrib]/a11y/accessibility-menu.js"], TeX: { extensions: ["AMSmath.js","AMSsymbols.js","noErrors.js","noUndefined.js"], equationNumbers: { autoNumber: "AMS" } } }); </script> 

In most hash applications, we do not have information about the actual keys until the hash table is filled and used. However, after  the
hash table is populated and put to use we may have a good idea about hash functions that may have avoided collisions and led to a better 
performance. Changing table size or hash function may be very expensive as it will require rehashing and data movements. To handle such
situation we look for a <i>perfect hashing</i> which maps elements to table slots without collisions. A <i>minimal perfect hashing</i>
is a perfect hashing that uses table size that has equal number of slots and keys. If the key set is known in advance (static) it is 
possible to design a minimal perfect hashing. Designing a perfect hashing is tedious but possible.

Creating a perfect hashing scheme is simple. It requires two-level approach with universal hashing at each level. The first level is 
almost same as chaining. The keys are hashed using a hash function chosen from a family of universal hash functions. The keys which happen to
hash into same chain are not stored in a linked list but stored in secondary hash table using an associated hash function. By  carefully
choosing the secondary hash we can guarantee that no collisions occur at the secondary level. However, we can provide the no collision
guarantee at the secondary level by using O($$n_j^2$$) table slots,  where $$n_j$$ is the number of keys hashing into the same slot in 
primary hash level. However, the use of universal hashing in primary level guarantees that no more than $$n/m$$ element can hash into
the same table slot in the primary hash level. 

Perfect hashing for static key sets applies to storing of keywords of a programming language. We use two hash functions $$h$$ and $$g$$
for it. The formula for computation of the hash value is:
<p style="text-align:center"> 
  $$h(k) = k.len + g(k_0) + g(k_1\ldots k_{k.len-1})$$
</p>
where $$k.len$$ is the length of the string $$k$$ and it is referred to as $$h$$ value of the word. Cichelli's method has three steps

1. Mapping,
2. Ordering,
3. Searching.

Mapping consists of determining the frequencies of the first and the last letters of each word and adding the frequencies to get a value for
the word. Ordering simply orders the words according to their values obtained from mapping step. Searching is used to find the $$g$$ values
for the first and the last letter so that the final hash value of each word is distinct. The algorithm may degenerate into exponential 
complexity if the word set is large. 

We use an example to explain the performance issues. Consider the set of words shown in the first table on the left part of the figure below. 
It has nine words (the names of states in India). The letter frequencies of the first and last letters of the words appear in the table in 
gray shade. 
<p style="text-align:center"> 
  <img src="../images/Cichell_Algo.png">
</p>
The scores of each word is computed by adding the frequencies of the first and the last letters. The unsorted list of words with scores
appear in the table to the left bottom. The sorted list appears to right of unsorted table. 

Now we explain the search step where $$g$$ value 0 is assigned to the letters and length of word is added to compute $$h$$ value. If $$h$$
value is unique we assign the corresponding table slot to the word. We continue the computation of the $$h$$ until a collision occurs. 
We resolve the collision by assigning consecutive values to the letter as indicated below.
<p style="text-align:center"> 
  <img src="../images/CichelliSearchStep.png">
</p>
The placement of elements in table slot may require repeated search that may degenerate into exponential time. Therefore, Cichelli's method
is applicable for hashing a small finite set of symbols. 


