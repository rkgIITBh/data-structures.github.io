## Shell Sort Algorithm

Shell sort uses a simple partitioning method over the given input sequence to gather and create 
logical subsequences. The mutual distance between adjacent elements in a sublist is a fixed
interval. Initially, interval length is <i>n/2</i>, where <i>n</i> is the number of elements in
the input. It requires log <i>n</i> passes of partitioning and sorting. We reduce the interval
length of partition by half in each pass. When the interval length is 0, we use compare-and-swap
between adjacent pair of elements to sort the array. Many researchers experimented with different
sequence of reducing interval lengths to explore shell sort's efficiency. However, in our 
description we use conventional interval length starting with <i>n/2</i>. 

We refer the interval length between a pair of the elements as gap <i>g</i> in our description.
For sorting the sublists we use insertion sort. Let  us represent the input sequence by
arr[0], arr[1], ..., arr[n-1]. Shell sort method is as follows:

- When <i>g</i> = n/2</i>, we gather the elements at a gap of n/2 starting with first element.
- It generates <i>n/2</i> subsequences each consisting of a pair of elements 
- We use insertion sort to sort the subsequences
- Repeat partitioning and sorting reducing the interval by half until interval becomes 0.
- Now we compare and swap adjacent pair of elements if necessary.  

In particular, for the second pass <i>g = n/4</i>. So we have to carray independent sorting 
of the following sub-sequences of the input 

- The subsequence: {arr[0], arr[n/4], arr[n/2], arr[3n/4], a[n]}
- The subsequence: {arr[1], arr[(n/4)+1], arr[(n/2)+1], arr[(3n/4)+1]}
- The subsequence: {arr[2], arr[(n/4)+2], arr[(n/2)+2], arr[(3n/4)+2]}
- and so on.

In general, if we sort the subarrays consisting of elements at a gap of <i>g</i> then 

- The subsequence: {arr[0], arr[g], arr[2g], arr[3g], ..., arr[kg]}, where k = &lfloor;n/g&rfloor;
- The subsequence: {arr[1], arr[g+1], arr[2g+1], arr[3g+1]. arr[kg+1]}
- The subsequence: {arr[2], arr[g+2], arr[2g+2], arr[3g+2]. arr[kg+2]}
- and so on.

After sorting all subsequences with gap <i>g</i>, we say the original sequence is g-sorted.
In summary, the input is (n/2)-sorted, (n/4)-sorted, (n/8)-sorted and so on. When it gets
0-sorted then the sorting is complete. Let us understand sorting process with an example.
Figure below illustrates the process of defining subsequences and sorting them.
<p style="text-align:center">
  <img src="../images/shellSortExample.png">
  
  <img src="../images/shellSortExample1.png">
</p>
The input consists of 10 elements. We use a reducing interval sequence {5, 2, 1, 0} for 
creating the sublists. In last pass, we 0-sort the sequence which requires only 2 swaps.
Notice that we do not physically create or partition to define the sublists. The 
procedure for sorting maintains the gap logically while sorting. 

As far as time complexity is concerned, the number of passes is O(log <i>n</i>). Insertion
sort takes worst-case time of O(<i>n<sup>2</sup></i>. So, the worst-case time is computed
as follows:

- Worst-case time for the last pass, i.e., sorting of elements 1-apart is n<sup>2</sup>
- Worst-case time for the pass before last, i.e., sorting of elements 2-apart is 2 * (n/2)<sup>2</sup>
- Worst-case time for sorting of elements 4-apart is 4 * (n/4)<sup>2</sup>
- and so on.

Therefore, the expression for time worst-case complexity is: 
<p style="text-align:center">
  n<sup>2</sup>(1 + 1/2 + 1/2<sup>2</sup> + ...+ 1/2<sup>log (n-1)</sup>) = 2n<sup>2</sup>.
</p>

The best-case time occurs when the input is a sorted sequence.

[Back to Index](../index.md)
