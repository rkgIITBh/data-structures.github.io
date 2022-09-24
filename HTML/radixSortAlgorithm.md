## Radix Sort

Radix sort uses <i>b</i> buckets, where <i>b</i> is the base or the radix of the number system. 
For the decimal numbers, the base is 10. So, we have to use ten buckets to sort decimal numbers.
It consists of log <i>n</i> passes. At each pass, we distribute the numbers into buckets, starting
with the least significant digit to the most significant digit. We expand the numbers by 
prepending the necessary number of zeros to make every number have the same number of digits. 
For example, if {170, 67, 39, 212, 98, 10, 5} is the input sequence, then prepend:

- A zero to all two-digit numbers, 
- Two zeros to all single-digit numbers.

The input sequence, thus, becomes {170, 067, 039, 212, 098, 010, 005}. In the first and second passes
the distribution of numbers to buckets is shown in the first rows of the figure below.

<p style="text-align:center">
  <img src="../images/radixSortExample.png">
</p>
  
At each pass, we distribute the numbers into the buckets in the sequence, starting with bucket zero.
On the third pass, when we distribute the numbers to buckets, 005, 039, 067, 095, and 098 are placed in
bucket 0. The numbers 170 and 212 are placed in buckets 1 and 2. It is shown in the third row of
the figure. For the sorted sequence, we empty the buckets in sequence.

- bkt-0 elements followed by bkt-1 and then bkt-2 elements as indicated.


[C Program for Radix Sort](../CODES/radixSort/index.md)

[Back to Index](../index.md)
