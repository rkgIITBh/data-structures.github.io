## Perfect Hashing

In most hash applications, we do not have information about the actual keys until the hash table is filled and used. However, after  the
hash table is populated and put to use we may have a good idea about hash functions that may have avoided collisions and led to a better 
performance. Changing table size or hash function may be very expensive as it will require rehashing and data movements. To handle such
situation we look for a <i>perfect hashing</i> which maps elements to table slots without collisions. A <i>minimal perfect hashing</i>
is a perfect hashing that uses table size that has equal number of slots and keys. If the key set is known in advance (static) it is 
possible to design a minimal perfect hashing. Designing a perfect hashing is tedious but possible.

Perfect hashing for static key sets applies to storing of keywords of a programming language. We use two hash functions $$h$$ and $$g$$
for it. The formula for computation of the hash value is:
<p style="text-align:center"> 
  $$h(k) = k.len + g(k_0) + g(k_1\ldots k_{len-1})$$
</p>
where $$k.len$$ is the length of the string $$k$$ and $$g(.)$$ is constructed using Cichelli's algorithm. Cichelli's method has three steps
1. Computation of letter frequencies in words,
2. Ordering the words,
3. Searching.

