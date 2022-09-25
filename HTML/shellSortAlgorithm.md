## Shell Sort Algorithm

Shell sort is a generalization of insertion sort. It creates logical subarrays of a given array
by gathering elements with a mutual distance called interval. Initially, interval length is 
greater than 1. We reduce the interval length in each pass. When interval length is 1, swap and
exchanges suffice to sort the array. Originally, shell sort used interval lengths <i>n/2</i>,
<i>n/4</i>, <i>n/8</i> ... Other researchers used different interval lengths to explore shell sort's
efficiency. 

