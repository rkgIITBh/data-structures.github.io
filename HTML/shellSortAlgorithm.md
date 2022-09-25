## Shell Sort Algorithm

Shell sort is a generalization of insertion sort. It creates logical subarrays of a given array
by gathering elements at a fixed distance called interval. Initially, interval length is 
<i>n/2</i>, where <i>n</i> is the number of elements to be sorted. We reduce the interval length
in each pass by half. When interval length is 1, we use compare-and-swap to sort the array.
Many researchers used different interval lengths to explore shell sort's efficiency. However,
in our description we use conventional interval length starting with <i>n/2</i>. 



