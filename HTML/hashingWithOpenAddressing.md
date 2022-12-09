


## Hashing with Open Addressing

Hashing with open addressing uses table slots directly to store the elements as indicated in the picture shown below:

<p style="text-align:center"}>
    <img src="../images/hashingOpenAddressing1.png">                                                       
</p>

The elements hashed to the same slots should be distributed to some other table slot. However, it is most likely that the alternative slot may
be occupied by another previously hashed element. Therefore, the hashing with open addressing requires a robust collision resolution technique 
to distribute the elements that map to the same table slot. There are many ways to resolve collisions. We discuss some well-established collision
resolution techniques along with insertions and deletions. We can view the probing function as mapping that can specify an ordering of probes 
for an empty slot in the table. It implies
<p style="text-align:center"}>
    $$h:U\times \{0, 1, 2, \ldots, m-1\}_{trials} \longrightarrow  \{0, 1, 2, \ldots, m-1\} $$                                          
</p>
The probling order essentially produces a vector 
<p style="text-align:center"}>
    $$h(k,1), h(k,2), \ldots, h(k,m-1) $$                                     
</p>
that is a permutation of $$\{0, 1, 2,\ldots, m-1}$$. <br>

The simplest collision resolution technique is known as linear probing. If a collision occurs, it tries to finds sequentially next available empty 
table slot. The method uses the hash function is given by 
<p style="text-align:center"}>
$$(h(k) + i)\mod m$$.
</p>

It forms clusters of hashed elements in few block of table slots. Starting with a random table slot $$x_0\in \{0, 1, \ldots, m-1\}$$, linear probing
generates the probe sequence $$x_0, x_1, \ldots, x_{m-1}$$, where $$x_i = (x_0 + i) \mod m$$. Therefore, it creates clustering of elements which hash
to the same table slot.It is called <i>primary clustering</i>. We can analyze the effect of primary clustering as follows. If $$j$$ consecutive slots
are occupied, then the next element mapping to any of them is $$j/m$$. With increase in length of cluster to $$j+1$$, the probability increases 
to $$(j+1)/m$$ for another new element being hashed to the cluster. It means that large clusters have a tendency to grow larger with more insertions.<br>

An alternative to linear probing is quadratice probing. It spreads the colliding elements by generating probing sequence where the $$i$$th probe 
<p style="text-align:center"}>
$$x_i = (x_0 + ik_1 + i^2k_2)$$, where $$k_1$$ and $$k_2$$ are nonzero constants.  
</p>
The idea is that the probe sequence should examine all slots of the table for discovering an empty slots to resolve a collision. The picture below
describes insert and search processes. The readers may notice that the flowcharts do not specify how many trials can be carried out. 
<p style="text-align:center"}>
    <img src="../images/hashingOpenAddressing2.png">                                                       
</p>
 
