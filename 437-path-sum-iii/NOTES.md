# Approach
1. Check prefix sum on a path
2. if sum==target then count++
3. if sum-target exists then count+=mp[sum-target]
4. then mp[sum]++ //otherwise problem if target==0 (CAUTION)
5. go left, go right
6. while going back mp[sum]-- // one path with current sum is excluded