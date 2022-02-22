class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        
        int dp[n+1][amount+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        
        
        for(int i=1;i<=amount;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[j][i]=dp[j-1][i];
                if(i>=coins[j-1])
                {
                    dp[j][i]+=dp[j][i-coins[j-1]];
                }
            }
        }
        
        return dp[n][amount];
    }
};