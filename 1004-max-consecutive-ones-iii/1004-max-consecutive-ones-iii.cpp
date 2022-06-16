class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int maxlen=0;
        
        
        for(int end=0;end<nums.size();end++)
        {
            if(nums[end]==0)
                k--;
            while(k<0)
            {
               if(nums[start]==0)
                   k++;
                start++;
            }
            
            if(k>=0)
            {
                maxlen=max(maxlen,end-start+1);
            }
        }
        return maxlen;
    }
};