class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp,10000,sizeof(dp));
        int n=coins.size();
        
        dp[0]=0;
    
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=coins[j])
                {
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        
        return (dp[amount]>amount?-1:dp[amount]);
    }
};