## Merge Sort

Merge sort is suitable for external sorting algorithm. It can handle massive amount of data that cannot
fit into main memory. The data resides in slow access memory such as disk. Chunks of data that can be
brought into main memory are sorted and written into disk. Then smaller files are combined by merging
the data. However, we only discuss the internal sorting algorithms. So, we assume that the data is
small enough to fit into main memory.

The main operation of merge sort is merging. A single element is vacously sorted. Merging of
two single elements  creates a sorted array of two elements. In general, a merging merging two sorted 
arrays of length <i>k</i> each and produces a single sorted array of length <i>2k</i>.  Therefore, by 
repeated merging, we finally get a sorted arrays of input sequence. The figures below
illustrates the operation of merging two sorted sequences of equal length.
<p style="text-align:center">
  <img src="../images/mergeTwoArrays.png"><br>
  Figure 1
</p>
As the figure shows we maintain three cursers, one each for the two given input arrays and one for 
the output array. 

- At each step we take one element from each array under the respective cursers.
- Compare the elements, the smaller is placed in the output array.
- Advance the curser for the input array from which element was sent to output.
- Advence the curser for the output array
- Repeat the step until all elements of one of the input arrays has been considered

After completing the above steps, one of the arrays will be left with the elements are not processed
in merging. These elements will be greater than the output elements. So we can transfer these
elements in same relative order in subsequent positions of output array. In the example showm in
the figure, after transfering 40 and 55 the first input array is exhausted. However, the input
array to the right will be still left with elements 72 and 89. Since the left input array will be
empty, the remaining elements 72 and 89 will get appended to the output in subsequent positions.
Therefore, the final merged sequence will be: 19, 25, 29, 38, 40, 55, 72, 89. The time complexity
of merging procedure is O(<i>m + n</i>), where <i>m</i> and <i>n</i> are respective sizes of the
two arrays.

The interesting part of merging problem is to merge in place, without using a third array for output.
Since there no additional array, we must rearranging the positions of elements in the input arrays.
Merging step works by swapping positions of the element pairs when first array has larger element
compared to that in the second array. The element which goes into the second array is rearranged to
keep the second array always in sorted order. When comparing elements we always begin with the 
first element of the second array. However, the curser for the first array advances after each merge
step. The figure below depicts the merging procedure.  
<p style="text-align:center">
  <img src="../images/mergeTwoArrays.png"><br>
  Figure 2
</p>  
The rearranging elements in the second array is similar to insertion sort procedure.

