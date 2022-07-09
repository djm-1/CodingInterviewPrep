# Approach
1. use two heaps one for storing capital (minheap) other for profit (maxheap)
2. push all pairs (capital, profit) into minheap
3. now loop till k
4. inside loop check if current w is able to get some projects done or not.
5. push those projects in maxheap by making (profit,capital) order
6. choose maximum one and add to w
7. return final w