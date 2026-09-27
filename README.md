# Merge Sort vs Quick Sort

This C assignment compares Merge Sort and Quick Sort while sorting package weights.

## Input

| Package | Weight |
| --- | ---: |
| P1 | 20 |
| P2 | 15 |
| P3 | 20 |
| P4 | 10 |
| P5 | 15 |
| P6 | 20 |
| P7 | 25 |
| P8 | 10 |

## Programs

- `mergesort.c` implements stable Merge Sort.
- `QuickSort.c` implements Quick Sort with Lomuto partitioning and the last element as pivot.

## Results

### Merge Sort

`P4(10) P8(10) P2(15) P5(15) P1(20) P3(20) P6(20) P7(25)`

Comparisons: **16**

### Quick Sort

`P4(10) P8(10) P5(15) P2(15) P3(20) P6(20) P1(20) P7(25)`

Comparisons: **16**

## Stability

Merge Sort is stable in this implementation because its merge function selects the
left item first when weights are equal. Quick Sort is not stable: equal-weight
packages change relative order during partitioning.

## Complexity

| Algorithm | Best | Average | Worst | Extra space |
| --- | --- | --- | --- | --- |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n^2) | O(log n) average; O(n) worst |

See `output.txt` for the exact program output, the trace files for each sorting
process, and `analysis.txt` for the comparison.
