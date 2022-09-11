## Merge Sort

Merge sort is suitable for external sorting algorithm. It can handle massive amount of data that cannot
fit into main memory. The data resides in slow access memory such as disk. Chunks of data that can be
brought into main memory are sorted and written into disk. Then smaller files are combined by merging
the data. However, we only discuss the internal sorting algorithms. So, we assume that the data is
small enough to fit into main memory.

The main operation of merge sort is merging. A single element is vacously sorted. Merging of
two single elements  creates a sorted array of two elements. In general, a merging merging two 
sorted arrays of length <i>k/i> each and produces a single sorted array of length <i>2k</i>.  
Therefore, by repeated merging, we finally get a sorted arrays of input sequence. The figures below
illustrates the operation of merging two sorted sequences of equal length.
<p style="text-align:center">
  <img src="../images/mergeSortExample.png"><br>
  Figure 1
</p>
If the initial sequences are not of equal length then we can pad the shorter sequence with sentinels
to define two equal length arrays. 
  
 
