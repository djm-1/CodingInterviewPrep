class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int dp[m+1][n+1];
        
        int ans=0;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else
                {
                    if(nums1[i-1]==nums2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else
                        dp[i][j]=0;
                }
                
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};