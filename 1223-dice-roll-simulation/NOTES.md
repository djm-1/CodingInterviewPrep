# Approach
1. It's a tough problem
2. base case-> roll==0 no rolling possible so empty seq possible, so return 1
3. Dp state=> dp(roll, last, len)
4. if current value==last (while traversing from 1->6) and len equals maxRoll then ignore (don't go ahead)
5. else go for next roll...if val==last then len+1 else new chain so len=1
6. for current state calculate summation and return
7. calc starts from last=0 and len=0 so last>=0 should be considered is conditions.