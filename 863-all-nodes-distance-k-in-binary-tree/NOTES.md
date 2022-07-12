# Approach
1. Turn tree into undirected graph by tracking parent beforehand
2. dfs on right left parent with k-1 level
3. if k==0 then store in ans