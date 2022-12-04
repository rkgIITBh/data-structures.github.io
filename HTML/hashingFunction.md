<script type="text/javascript"
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    tex2jax: {
      inlineMath: [['$','$'], ['\\(','\\)']],
      processEscapes: true},
      jax: ["input/TeX","input/MathML","input/AsciiMath","output/CommonHTML"],
      extensions: ["tex2jax.js","mml2jax.js","asciimath2jax.js","MathMenu.js","MathZoom.js","AssistiveMML.js", "[Contrib]/a11y/accessibility-menu.js"],
      TeX: {
      extensions: ["AMSmath.js","AMSsymbols.js","noErrors.js","noUndefined.js"],
      equationNumbers: {
      autoNumber: "AMS"
      }
    }
  });
</script>

## Hash Functions

Hashing uses a hash function to map a key (element) to an index position in hash table. The function should have the following
characteristics:

- Low cost
- Uniformity
- Deterministic

Low cost implies the hash function should be computable in time of O(1). Uniformity means hash function should distribute the
keys equally likely in its range space or the index space of the hash table. Hash function is deterministic if gives same hash 
value for a given input. If hash function is not deterministic then it might give different index values in different operations.
So, we cannot access a key from the stored slot. 

The well known hash functions use following four methods:

- Division
- Multiplication
- Midsquare
- Folding

Division method is the simplest and most well used hashing function. It is given by:
<p style="text-align:center">
  <i>h(x)</i> = <i>x</i> mod <i>m</i>, where <i>m</i> is the hash table size.
</p>
Let us analyze the characteristics of division function and its impact on different table sizes <i>m</i>.
First consider the value of <i>m = 2<sup>p</sup></i>, then division function will map any key <i>x</i> only
to its lower order <i>p</i> bits. Therefore, a table size that is a power of 2 is a bad choice irrespective of key space. In fact, the 
division function maps all values of <i>x = am + b</i> map to same table slot <i>b</i>. Therefore, even the choice of a prime value
for <i>m</i> may not work out. 

Let us try find out the conditions for which division function may work. We assume the base of the number system to be
<i>b</i> such that <i>b</i> &#8801; 1 (mod <i>m</i>). Now consider a key value of the form
<p style="text-align:center">
  $$k \mod m = \left(\sum_0^{r-1} k_i b^i\right) \mod m $$
</p>
Since $$b \equiv 1\mod m$$, we can replace it by $$(qm+1)$$. So, the RHS expression of the above equation becomes
<p style="text-align:center">
  $$k \mod m = \left(\sum_0^{r-1} k_i (qm+1)\right) \mod m $$
</p>


The next function is known as multiplication function. It relies on finding product of <i>x</i> by a randomly chosen fraction
between 0 and 1 and extracting the middle bits of 
