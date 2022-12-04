<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML"> </script> <script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: { inlineMath: [['$','$'], ['\\(','\\)']], processEscapes: true}, jax: ["input/TeX","input/MathML","input/AsciiMath","output/CommonHTML"], extensions: ["tex2jax.js","mml2jax.js","asciimath2jax.js","MathMenu.js","MathZoom.js","AssistiveMML.js", "[Contrib]/a11y/accessibility-menu.js"], TeX: { extensions: ["AMSmath.js","AMSsymbols.js","noErrors.js","noUndefined.js"], equationNumbers: { autoNumber: "AMS" } } }); </script> 

## Hashing by Chaining

A simple, uniform hash function spreads a set of random keys so that each key is equally likely to be hashed in any of the table slots.
Let $$P(k)$$ be the probability of $$k$$ being hashed into a table slot. Distributiveness of the hash means each slot 
$$j = 0, 1, \ldots, m-1$$ to be occupied equally likely. <br>
<p style="text-align:center">
  $$\sum_{k|h(k) = j} P(k) = \frac{1}{m}$$
</p>
In hashing by separate chaining, the keys that map to the same table slot are chanined together in the form of a linked list. The
hash table contains pointers to these linked list. In other words, the hash table is an array of ponters of size $$m$$.
The expected length of each linked list is $$\frac{n}{m}$$ which is known as load factor and denoted by $$\alpha$$.<br>
Recall that the hashing by chaining can be viewed pictorially as follows:
<p style="text-align:center">
  <img src="../images/hashingBySeparateChaning.png">
</p>  
