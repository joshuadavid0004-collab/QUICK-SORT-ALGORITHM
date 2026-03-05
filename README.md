NAME: JOSHUA DAVID
REG NO. EB3/67259/23
# INTRO-SORT-ALGORITHM

The Introspective Sort (IntroSort) is a sort algorithm amalgamation algorithm, which uses:
Quick Sort
Heap Sort
Insertion Sort
The algorithm begins with QuickSort, followed by a transition to HeapSort when the recursion depth becomes too high, and finally uses InsertionSort afterward when the partitions become too small. This design is quick and it has the performance guarantee.
Best Case Time Complexity
Condition
The best case is where the pivot divides the array into two halves, at each of the partitions.
Work Done
At each level:
The sample is divided into two equal parts.
The number of elements that are processed at a level is n.
Number of levels:
log2 n
Total work:
n x log2 n
Best Case Complexity
O(n log n)
Explanation
QuickSort is effective in situations when the partitions are equally divided; hence, IntroSort resembles QuickSort in an ideal situation.
Mean Complexity Case Time.
Condition
The array is usually partitioned unequally and reasonably among the pivot.
Work Done
In spite of this fact, the degree of recursive levels is still estimated to be:
log2 n
the proportion of the overall operations will be in proportion to:
n log n
Average Case Complexity
O(n log n)
Explanation
The overwhelming percentage of real-life data sets end in close balanced partitions and thus IntroSort generally also behaves like QuickSort when good pivots are picked.
Worst Case Time Complexity
Condition
The worst case is in which the QuickSort again and again picks bad pivots like:
Already sorted arrays
Reverse sorted arrays
This is what brings about the recursion depth:
n
Pure QuickSort Worst Case
O(n2)
However, IntroSort does not have this problem.
How IntroSort Fixes It
IntroSort limits the recursion level:
depthLimit = 2 log2 n
Recursion ought not to be further than this:
QuickSort - is an HeapSort modification.
Theta: Hepasort has made sure that it is not simple:
O(n log n)
Worst Case Complexity
O(n log n)
Algorithm Efficiency
It is because IntroSort is considered to be the most efficient comparison-based sorting algorithm because it incorporates the strength of the other algorithm.
Advantages
Worst case ensured O (n log n).
Very fast in practice
Eliminates the worst-case of QuickSort.
Inserts With small arrays, it has a faster sort (Insertion sort).
Adaptive decisions of partition improve the quality of partitions.
Used in real-world systems
Limitations of IntroSort
There are weaknesses to the strengths of IntroSort.
Complex Implementation
The IntroSort is by no means a simple algorithm like:
Merge Sort
Quick Sort
Heap Sort
This can be attributed to the fact that it comprises three algorithms.
Not Stable
The IntroSort algorithm is not a stabilized sorting algorithm.
The order of the similar items is changeable.
Recursion Overhead
Recursive calls are also a burden to very large datasets but the depth of recursion is limited.
A Little bit of Higher Memory than HeapSort.
HeapSort uses:
O(1) memory
IntroSort uses:
O(log n) memory
because of recursion.
