# Approach
1. BFS on strings
2. put all strings in a set including startstring (to avoid duplicate)
3. check if endstring exists or not (return 0 then)
4. push start string in queue
5. keep map of visited
6. if word diff is 1 then neighbour (directed ofc)
7. delete string from set after pushing into stack because, we don't need to count incoming edges anymore, from queue we will count outgoing edges only.
8. count level and return level+1 for number of steps