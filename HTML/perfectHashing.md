## Perfect Hashing

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML"> </script> <script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: { inlineMath: [['$','$'], ['\\(','\\)']], processEscapes: true}, jax: ["input/TeX","input/MathML","input/AsciiMath","output/CommonHTML"], extensions: ["tex2jax.js","mml2jax.js","asciimath2jax.js","MathMenu.js","MathZoom.js","AssistiveMML.js", "[Contrib]/a11y/accessibility-menu.js"], TeX: { extensions: ["AMSmath.js","AMSsymbols.js","noErrors.js","noUndefined.js"], equationNumbers: { autoNumber: "AMS" } } }); </script> 

In most hash applications, we do not have information about the actual keys until the hash table is filled and used. However, after  the
hash table is populated and put to use we may have a good idea about hash functions that may have avoided collisions and led to a better 
performance. Changing table size or hash function may be very expensive as it will require rehashing and data movements. To handle such
situation we look for a <i>perfect hashing</i> which maps elements to table slots without collisions. A <i>minimal perfect hashing</i>
is a perfect hashing that uses table size that has equal number of slots and keys. If the key set is known in advance (static) it is 
possible to design a minimal perfect hashing. Designing a perfect hashing is tedious but possible.

Perfect hashing for static key sets applies to storing of keywords of a programming language. We use two hash functions $$h$$ and $$g$$
for it. The formula for computation of the hash value is:
<p style="text-align:center"> 
  $$h(k) = k.len + g(k_0) + g(k_1\ldots k_{k.len-1})$$
</p>
where $$k.len$$ is the length of the string $$k$$ and $$g(.)$$ is constructed using Cichelli's algorithm. Cichelli's method has three steps
1. Computation of letter frequencies in words,
2. Ordering the words,
3. Searching.
The algorithm may degenerate into exponential complexity if the symbol set is large. We use an example to explain the performance issue
for large symbol set.


