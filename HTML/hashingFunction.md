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
  <i>x</i> mod <i>m</i> = &#40; &#8721;<sup>r</sup><sub>0</sub> <i>x<sub>i</sub> b<sup>i</sup></i> &#41; mod <i>m</i>
</p>

$(".latex").latex();
<div class="latex">  
    \int_{0}^{\pi}\frac{x^{4}\left(1-x\right)^{4}}{1+x^{2}}dx =\frac{22}{7}-\pi  
</div>


The next function is known as multiplication function. It relies on finding product of <i>x</i> by a randomly chosen fraction
between 0 and 1 and extracting the middle bits of 
