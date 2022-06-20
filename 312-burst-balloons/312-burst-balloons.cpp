class Solution {
    int dp[500][500];
public:
    int solve(vector<int>& nums, int l, int r)
    {
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int n=nums.size();
        int maxi=INT_MIN;
        for(int k=l;k<=r;k++)
        {
            int left=solve(nums,l,k-1);
            int right=solve(nums,k+1,r);
            int curr=(l-1>=0?nums[l-1]:1)*nums[k]*(r+1>=n?1:nums[r+1]);
            maxi=max(maxi,left+right+curr);
        }
        return dp[l][r]=maxi;
    }
    int maxCoins(vector<int>& nums) {
         
        int n=nums.size();
        
        memset(dp,-1,sizeof(dp));
        solve(nums,0,n-1);
        return dp[0][n-1];
    }
};