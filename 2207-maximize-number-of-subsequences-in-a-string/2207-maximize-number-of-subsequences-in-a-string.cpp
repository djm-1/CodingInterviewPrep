class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long count1=0,total=0,count2=0;
        for(auto c:text)
        {
            // if both are equal then we need to check for pattern completion first.
            if(c==pattern[1])
                total+=count1,count2++;
            if(c==pattern[0])
                count1++;
        }
        
        return total+max(count1,count2);
    }
};