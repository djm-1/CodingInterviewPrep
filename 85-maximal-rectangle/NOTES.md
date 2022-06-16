# Approach
same approach like maximum area in histogram
1. Row wise prefix sum of heights but if matrix[i][j]=0 then put zero, because height which float in air, that can't be compared at same level.
2. then calculate row-wise MAX_AREA_HISTOGRAM
3. return max of them.