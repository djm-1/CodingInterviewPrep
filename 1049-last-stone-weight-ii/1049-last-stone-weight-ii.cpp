class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int sum=0;
        for(auto x:stones)
            sum+=x;
        int target=sum/2;
        int n=stones.size();
        bool dp[n+1][target+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=true;
                else if(i==0 && j>=1)
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
                else if(i>=1 && j>=1)
                {
                    if(stones[i-1]<=j)
                        dp[i][j]=dp[i-1][j]|dp[i-1][j-stones[i-1]];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        int mini=INT_MAX;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=target;j++)
                if(dp[i][j])
                    mini=min(mini,abs(sum-2*j));
        
        return mini;
    }
};