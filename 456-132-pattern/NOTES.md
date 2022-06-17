# Approach
1. maintain a decreasing 3-2 monotonic stack
2. 1 will be at the left of 3...choose it as small as possible
3. To do that maintain a minimum array
4. if minimum(st.top)!=st.top => smaller value exists on left and it also should be lesser than incoming value. Then answer exists...return true
5. return false by default outside of loop