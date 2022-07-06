# Approach
1. very good qn on search in a sorted matrix
2. from the bottom right corner start dfs to top and left with boundary conditions
3. mark negative nodes as positive to mark as visited (avoid double count of -ve no.s)
4. if bottom right element in >=0 then return 0 in beginning.
5. Complexity O(n+m)