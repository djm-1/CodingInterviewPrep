class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int local_max=1,global_max=1;
        
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
                local_max++;
            if(nums[i]<=nums[i-1]||i==n-1)
            {
                global_max=max(global_max,local_max);
                local_max=1;
            }
        }
        
        return global_max;
    }
};