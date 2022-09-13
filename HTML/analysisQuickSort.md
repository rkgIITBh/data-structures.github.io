## Analysis of Quick Sort

<strong>Worst-case analysis</strong>

Worst-case behaviour occurs if excluding the partitioning elements, partition returns one array
of size <i>n - 1</i>. The worst-case materializes when we have a sorted input. The cost of 
partitioning in this case is &Theta;(<i>n</i>). The recurrence relation for running time is:
<p style="text-align:center">
  <img src="../images/quickSortWorstcase.png" width="250" height="30">
</p>

<p style="text-align:center">
  <img src="../images/quickSortWorstcase2.png" width="380" height="80">
</p>

<strong>Best case analysis</strong>

The best-case occurs if the partition produces two equal subarrays, i.e., if the pivot is
the median element. In this case, the partition sizes are:

- one of size &lfloor;<i>n/2</i>&rfloor; and 
- another of size &lceil;<i>n/2</i>&rceil;

The recurrence equation for time complexity is given by

<p style="text-align:center">
  <img src="../images/quickSortBestcase1.png" width="380" height="100">
</p>
Using <i>T(1) = 0</i>, 2<sup>k</sup> = <i>n</i>, we get <i>k = log n</i>. Simplifying the above
recurrence equation:
<p style="text-align:center">
  <img src="../images/quickSortBestcase2.png" width="320" height="30">
</p>

<strong>Balanced partitioning</strong>

The average case of quick sort is more close to the best case than worst case. It is because balance
of partitioning is reflected in recurrence for running time. Suppose the partitioning always produces
9-to-1 proportional split, then the recurrence relation will then be:
<p style="text-align:center">
  <img src="../images/quickSortBalancedcase1.png" width="320" height="30">
</p>


<p style="text-align:center">
  <img src="../images/quickSortRecursionTree.png">
</p>



<strong>Average case analysis</strong>

Quick sort average case analysis is based on the following assumptions:

- All permutation of the input sequence is equally likely so that we can choose the first element as the pivot
- The pivots used at all-recursive levels are random 

Therefore, the recurrence formula for time complexity is:
<p style="text-align:center">
  <img src="../images/quickSortRecurrenceFormula.png" width="380" height="50">
</p>
Since we move the pivot out of the way during partitioning, one comparison takes place for
each of <i>n-1</i> elements. The remaining part of the recurrence relation is explained as 
follows. If <i>i</i> elements are in one partition then <i>n-i-1</i> elements are in the other
partition. Now by the symmetry of expression within the summation sign, we simplify the recurrence
relation as:
<p style="text-align:center">
  <img src="../images/quickSortFormula1.png" width="260" height="40">
</p>                                                                
We multiply both sides of the above equation by <i>n</i> and substract <i>T(n-1)</i>
from <i>T(n)</i> and get:                                                              
<p style="text-align:center">
  <img src="../images/quickSortFormula2.png" width="400" height="35">
</p>
Rearranging terms and simplifying, we have:
<p style="text-align:center">
  <img src="../images/quickSortFormula3.png" width="250" height="30">
</p>
Now the recurrence is in a form we can solve by unfolding the recurrence.
<p style="text-align:center">
  <img src="../images/quickSortFormula4.png" width="400" height="250">
</p>
Approximating summation by integral 
<p style="text-align:center">
  <img src="../images/quickSortFormula5.png" height="30" width="60">
</p>
we get:
<p style="text-align:center">
  <img src="../images/quickSortFormula6.png" width="350" height="60">
</p>
