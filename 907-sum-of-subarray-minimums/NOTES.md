# Approach
1. Idea is to check how many subarrays can we make by including current element as minimum
2. If there is no element smaller than curremt element to right or left then current element is the minimum
3. Possible subarrays on right excluding current element=NSR-i
4. Possible subarrays on left excluding current element=i-NSL
5. if NSL is not there keep -1, if NSR not there keep N
5. sum+=nums[i[* (NSR-i) * (i-NSL)