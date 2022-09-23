## Radix Sort

Radix sort uses <i>b</i> buckets, where <i>b</i> is the base or the radix of the numbers we want sort.
For the decimal numbers the base is 10. So, it needs 10 buckets to sort a set of decimal numbers.
At each pass, we distribute the numbers into buckets starting with the least significant digit to 
the most significant digit. We expand the numbers by prepending necessary number of 0s so that
every number has the same the number of digits. For example, if {170, 67, 39, 212, 98, 10, 5} is
the input sequence, then prepend:

- A zero to all two digit numbers, 
- Two zeros to all single digit numbers.

So, the input sequence becomes {170, 067, 039, 212, 098, 010, 005}. In first pass the distribution
of numbers to buckets is as follows:

| Bucket  |  Number    |
|---------|------------|
|0        | 170        |
|1        | -          |
| 2       | 212        |
| 3       | -          |
| 4       | -          |
|5        | 095,005    |
| 6       |     -      |
| 7       | 067        |
| 8       | 098        |
| 9       | 039        |
