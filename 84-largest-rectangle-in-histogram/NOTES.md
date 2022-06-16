# Approach
1. Greater element will not create problem but smaller elements will.
2. So, we need to find NSR and NSL.
3. if NSR doesn't exist, then take it's index as N
4. If NSL doesn't exist then take it's index as -1
5. Now, the area is (NSR-NSL-1)* currheight
6. Find max of those.
​
# Alternative approach in one pass
1. To handle a small element at the end of array, add a zero at end
2. stack should be in a decreasing fashion
3. while popping an element left=top after popping and right=incoming i
4. if left exists (stack not empty after popping current element) then Width=i-st.top()-1
5. else Width=i