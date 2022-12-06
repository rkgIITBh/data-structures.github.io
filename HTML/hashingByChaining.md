<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML"> </script> <script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: { inlineMath: [['$','$'], ['\\(','\\)']], processEscapes: true}, jax: ["input/TeX","input/MathML","input/AsciiMath","output/CommonHTML"], extensions: ["tex2jax.js","mml2jax.js","asciimath2jax.js","MathMenu.js","MathZoom.js","AssistiveMML.js", "[Contrib]/a11y/accessibility-menu.js"], TeX: { extensions: ["AMSmath.js","AMSsymbols.js","noErrors.js","noUndefined.js"], equationNumbers: { autoNumber: "AMS" } } }); </script> 

## Hashing by Chaining

A simple, uniform hash function spreads a set of random keys so that each key is equally likely to be hashed in any table slot.
Let $$P(k)$$ be the probability of $$k$$ being hashed into a table slot. Distributiveness of the hash means each slot 
$$j = 0, 1, \ldots, m-1$$ to be occupied equally likely. <br>
<p style="text-align:center">
  $$\sum_{k|h(k) = j} P(k) = \frac{1}{m}$$
</p>
In hashing by separate chaining, collision resolution is simple. All keys that map to the same table slot are chained together
in a linked list. The hash table slots contain pointers to these linked lists. In other words, the hash table is an array of 
pointers of size $$m$$. The expected length of each linked list is $$\frac{n}{m}$$ which is known as load factor and denoted by
$$\alpha$$. The hashing by chaining can be viewed as follows:
<p style="text-align:center">
  <img src="../images/hashingBySeparateChaning.png">
</p>  
A lookup or search for an element in the hash table requires two steps:

1. Compute the hash value of the element
2. Index the table using the hash value to reach the linked list and search it for the element.

For the analysis of time complexity, we have to consider two cases: 

1. Time for a successful search
2. Time for an unsuccessful search

Analysis of time complexity for unsuccessful search is easy with the assumption that the hash function is simple and uniform. 
An element may belong to any of the $$m$$ chains. As explained earlier, the length of any  
chains or the linked list is $$n/m = \alpha$$. The average time to search for an element in a linked list of length $$\alpha$$ is 
$$\alpha/2$$. Since the searching also involves computing the hash value for the table index before searching the corresponding 
linked list, the time  for an unsuccessful search is $$(1+\alpha/2)$$.<br>

The analysis for time complexity for a successful search is a bit involved. We need to visualize the insertions as it happens into
different chains. The first part of the analysis, of course, is to assume that the hashing function is simple and uniform. So, 
while inserting any element, we may hit any table slot equally likely. However, after that, we append the incoming element 
to the corresponding list. The expected length of the list to which the element $$i$$ gets inserted is $$(i-1)/m$$. <br>

To calculate the complexity of the unsuccessful search, we need to find the average of all insertions to the hash table.
The expression for the above is:
<p style="text-align:center">
  $$\begin{split}
  \frac{1}{n}\sum_{1}^{n} (1+\frac{i-1}{m}) & = 1 + \frac{1}{mn}\sum_{1}^n (i-1)\\
  & = 1 + \frac{n(n-1)}{2m.n}\\
  & = 1 + \frac{n-1}{2m}\\
  & = 1 + \alpha/2 - \frac{1}{2m}
  \end{split}$$
</p>
Therefore, the average time complexity of an unsuccessful search is (1 + $$\alpha/2$$) <br>

We did not address the issue of programming. However, hashing by separate chaining does not require much complex programming. We have already
learned about programming with linked lists. Computations concerning hash functions are pretty simple. So we leave it to the readers to
develop programs. However, to help users develop their own codes we provide pseudo codes of the important parts.

We assume that the hash table only stores integers. So the node structure may be defined as follows:
```
typedef struct hTnode {
int val ;
struct node ∗ next ;
} node ;

void initializeHT ( node ∗ hashTable [], int m) {
int i;
for (i = 0; i < m; i ++)
hashTable [i] = NULL;
}

node ∗ searchKey( node ∗ hashTable [ ] , int k ) {
node ∗p ;
p = hashTable [h(k)] ; 
while ((p != NULL) && ( p−>val != k))
    p = p−>next;
if ( p−>val == k )
    return p ;
else
    return NULL ;
}

void insertKey( node ∗ hashTable [] , int k ) {
    node ∗ newNode ;
    node ∗ ptr = searchKey ( hashTable , k) ;
    if ( ptr == NULL ) {
        newNode = ( node ∗ ) malloc ( sizeof(node) ) ;
        newNode−>v a l = k ;
        newNode−>n e x t = hashTable [ h ( k ) ]
        hashTable [ h ( k ) ] = newNode ;
    }
}

```
In the next blog, we will discuss hashing with open addressing.

[Back to Index](../index.md)
