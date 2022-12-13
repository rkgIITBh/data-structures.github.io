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
          $$\mbox{card}\{h| h(k_1) = h(k_2)\} = \frac{|{\cal H}|}{m}$$
</p>
If $$h$$ is randomly chosen from $${\cal H}$$ then the probability of $$h$$ mapping two different keys to the same table slot is given by
 <p style="align-text:center">
   $$\begin{split}      
        \frac{\mbox{card}\{h| h(k_1) = h(k_2)\}}{|{\cal H}|} &= \frac{|{\cal H}|/m}{|{\cal H}|}\\
         &= \frac{1}{m}
  \end{split}$$
</p>         
<strong>Theorem for Universal Hash Function</strong>

Suppose $$n$$ keys to be hashed into a table of size $$m$$, then choose a hash function $$h$$ randomly from the set $${\cal H}$$, Under the
stated conditions, the expected number of collisions with any key $$k$$ is given by:
<p style="align-text:center">
$$E(\mbox{# of collision with }k) =\frac{n}{m} = \alpha$$
</p>
<strong>Proof:</strong>

The theorem implies that if there exists a set of universal hash functions then choosing one function from the set ensure that keys are evenly
distributed.

To prove the theorem, we choose a random variable $$C_{k}$$ denoting the number of keys that collide in the hash table $$HT$$ with key $$k$$.
Let us define
<p style="align-text:center">
$$c_{k_1k_2} = \begin{cases}
          1\mbox{, if } h(k_1) = h(k_2)\mbox{ for keys } k_1\ne k_2\\
          0\mbox{, otherwise}
          \end{cases}$$
</p>
The expected value $$E(c_{k_1k_2}) = 1/m$$ because $$h\in {\cal H}$$. But $$C_{k_1} = \sum_{k_2\in HT-\{k_1\}}c_{k_1k_2}$$. Therefore, 
we can derive $$E(C_{k_1})$$ as follows:
<p style="align-text:center">
$$\begin{split}
      E(C_{k_1}) &= E\left(\sum_{k_2\in HT-\{k_1\}}c_{k_1k_2}\right)\\
          &= \sum_{k_2\in HT-\{k_1\}}E(c_{k_1k_2})\\
          &= \sum_{k_2\in HT-\{k_1\}}\frac{1}{m}\\
          &= \frac{n-1}{m} < \alpha
          \end{split}$$
</p>
In the above analysis, we have considered colliding keys $$k_1$$ and $$k_2$$ to be distinct. However, we also need to account for a key to 
collide with itself to account for all colliding keys. So, the total number of collisions is $$1+\alpha$$.
     
<strong>Construction of Universal Hash Functions</strong>
         
The construction described below works when $$m$$ is prime. In the construction, we assume every representing a number that consists of
$$r+1$$ base $$m$$ digits. For example, let
$$m = 11$$ and we have a key $$k = 4789$$. The key $$k$$ represents an equivalent decimal number $$4.11^3 + 7.11^2 + 8.11^1 + 9.11^0$$. 

- Choose a vector $$[a_0 a_1 \ldots a_r]$$, where $$0\le a_i < m$$.
- Compute $$h_a(k) = \left(\sum_{0}^{r} a_ik_i\right) \mod m$$, where $$k = k_{r}k_{r-1}\ldots k_0$$. 

We can have $$m^{r+1}$$ vectors like $$a$$. In other words, we can construct $$m^{r+1}$$ hash functions by picking a random vector of the type $$a$$. Only
thing we have to prove now is that the family of hash functions represents a universal hash.
