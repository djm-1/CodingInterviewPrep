# Approach
1. if nums[index] is visited then index+1 is duplicate
2. in 2nd pass if nums[i]>0 then it means no one came here via nums element visit, so this index+1 doesn't exist in nums array. so store index+1 as missing number