# Approach
1. Greater element will not create problem but smaller elements will.
2. So, we need to find NSR and NSL.
3. if NSR doesn't exist, then take it's index as N
4. If NSL doesn't exist then take it's index as -1
5. Now, the area is (NSR-NSL-1)* currheight
6. Find max of those.