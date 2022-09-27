## Odd Even Sorting Algorithm

Odd even sorting algorithm is designed around Bubble sorting technique. There are two
distinct phases for odd even sorting, namely, odd and even. In odd phase, odd indexed
elements are compared with adjacent elements. If the pair is out of order then we swap
them. The compare and swap is repeated in even phase with even indexed elements. The 
odd and even phases are repeated until all elements are sorted. After <i>n</i> phases
list is sorted. Since each phase has <i>n/2</i> elements, it require <i>n/2</i> 
comparisons. Therefore, the complexity of the algorithm is O(<i>n<sup>2</sup></i>). 



