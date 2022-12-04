
## Hashing by Chaining

A simple, uniform hash function spreads a set of random keys so that each key is equally likely to be hashed in any of the table slots.
Let $$P(k)$$ be the probability of $$k$$ being hashed into a table slot. Distributiveness of the hash means each slot 
$$j = 0, 1, \ldots, m-1$$ to be occupied equally likely. <br>
<p style="text-align:center">
  $$\sum_{k|h(k) = j} P(k) = \frac{1}{m}$$
</p>
