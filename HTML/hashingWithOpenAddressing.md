


## Hashing with Open Addressing

Hashing with open addressing uses table slots to store the elements. Since chaining is not used, the resolution of collisions has to be performed
directly over the table slots. There are many ways to resolve collisions. We discuss some well-established collision resolution techniques along 
with insertions and deletions. The simplest solution is linear probing. It uses next available empty table slot whenever a collision occurs. Collision
resolution by linear probing clusters the elements with the same hash value together. These elements appear consecutively. An alternative to linear
probing is quadratice probing or random probing. The probing apply hash functions repeatedly to locate an empty alternative slot to when a
collision occurs explained in the diagram below.

<p style="text-align:center"}>
    <img src="../images/hashingWithOpenAddr1.png">                                                       
</p>
                                                 
