## Universal Hashing

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML"> </script> <script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: { inlineMath: [['$','$'], ['\\(','\\)']], processEscapes: true}, jax: ["input/TeX","input/MathML","input/AsciiMath","output/CommonHTML"], extensions: ["tex2jax.js","mml2jax.js","asciimath2jax.js","MathMenu.js","MathZoom.js","AssistiveMML.js", "[Contrib]/a11y/accessibility-menu.js"], TeX: { extensions: ["AMSmath.js","AMSsymbols.js","noErrors.js","noUndefined.js"], equationNumbers: { autoNumber: "AMS" } } }); </script> 

Uinversal hashing randomly selects a hash from a family of hash functions $${\cal H}$$ instead using a prespecified hash function. The idea is that
a good hash function may emerge by setting up a performance test of different hash programs with a benchmark test suite. These programs may also be
developed by rival developers who create families of hash functions to establish superiority of their products. Randomization helps the rivals to 
prevent their adversaries from gaining an insight of the products they offer. An adversary can check the code of a rival, but cannot guess which
hash is used due to randomization. The above hashing scheme is called universal because it will work against an adversary with a promised expectation.
The hashing scheme gaurantees that the probability of two distinct keys $$k_1$$ and $$k_2$$ mapped to the same table slot is $$1/m$$, where $$m$$
is the table size.

<strong>Definition of Universal Hash Function</strong>

Let the keys be drawn from a univers $$U$$, and let $${\cal H}$$ be a finite collection of hash functions which maps keys to $$\{0, 1, 2, \ldots, m-1\}$$.
$${\cal H}$$ is universal if for all $$k_1\ne k_2$$ the cardinality of the set
<p style="align-text:center">
          $$card\{h: h(k_1) = h(k_2)\} = \frac{|{\cal H}|}{m}$$
</p>
If $$h$$ is randomly chosen from $${\cal H}$$ then the probability of $$h$$ mapping two different keys to the same table slot is given by
 <p style="align-text:center">
   \begin{split}      
        \frac{card\{h: h(k_1) = h(k_2)\}}{|{\cal H}|} &= \frac{|{\cal H}|}{m}/|{\cal h}|}\\
         &= \frac{1}{m}
  \end{split}
</p>         
Suppose $$n$$ keys to be hashed into a table of size $$m$$, then choose a hash function $$h$$ randomly from the set $${\cal H}$$, Under the
stated conditions, the expected number of collisions with any key $$k$$ is given by:
<p style="align-text:center">
$$E(\mbox{\# of collision with }k) =\frac{n}{m} = \alpha$$
</p>
