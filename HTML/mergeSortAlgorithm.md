## Merge Sort

Merge sort is suitable for external sorting algorithm. It can handle massive amount of data that cannot
fit into main memory. The data resides in slow access memory such as disk. Chunks of data that can be
brought into main memory are sorted and written into disk. Then smaller files are combined by merging
the data. However, we only discuss the internal sorting algorithms. So, we assume that the data is
small enough to fit into main memory.

The main operation of merge sort is merging. Merging is a method to merge two sorted arrays in a single
sorted file. A single element is vacously sorted. So, we can merge two single elements to create a
sorted array of two elements. Then merge two sorted arrays into an array of four sorted elements. By
repeated merging, we create sorted arrays of twice the length of sorted arrays in the previouse 
merge step. 

