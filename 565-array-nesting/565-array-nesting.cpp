class Solution {
public:
    
    int dfs(int i, vector<int>&nums, int dep){
        if(nums[i]==i||nums[i]==-1)
            return dep;
        int val=nums[i];
        nums[i]=-1;
        return dfs(val,nums,dep+1);
    }
    
    int arrayNesting(vector<int>& nums) {
        int maxi=1;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                maxi=max(maxi,dfs(i,nums,0));
            }
        }
        
        return maxi;
    }
};