class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
            sum+=x;
        if(sum%2==1)
            return false;
        else{
            
            sum/=2;
            int n=nums.size();
            int i,j;
            bool dp[n+1][sum+1];
            for(i=0;i<=n;i++)
                dp[i][0]=true;
            for(j=1;j<=sum;j++)
                dp[0][j]=false;
            
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=sum;j++)
                {
                    if(nums[i-1]>j)
                        dp[i][j]=dp[i-1][j];
                    else
                    {
                        dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                    }
                }
            }
            
            return dp[n][sum];
        }
    }
};