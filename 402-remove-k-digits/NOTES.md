# Approach
1. Increasing order is the best order for minimum number
2. delete from stack as long as k>0
3. take out chars from stack and make a string and reverse it
4. now eliminate first 0's. if i reaches end of string then return "0"
5. if k>0 then eliminate from back using j because bigger digits are there only
6. if j>=i then substring ans else "0"