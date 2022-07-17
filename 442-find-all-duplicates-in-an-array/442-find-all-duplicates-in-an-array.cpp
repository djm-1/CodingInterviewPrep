class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int idx=abs(nums[i])-1;
            if(nums[idx]>0)
                nums[idx]*=-1;
            else
                ans.push_back(idx+1);
        }
        
        return ans;
    }
};