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
to its lower order <i>p-1</i> bits. Therefore, a table size that is a power of 2 is a bad choice irrespective of key space.

