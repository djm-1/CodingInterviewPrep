# Approach
1. Play reverse topological Sort on outdegree
2. keep track of parents instead of children
3. Store them whose outdegree is 0
4. Alternatively, reverse the edges and apply toplogical sort to find answer