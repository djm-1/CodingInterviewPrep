class Solution {
public:
    
    int dp[100005][4][4];
    
    int solve(int i, int n, int buy, vector<int>&prices, int k){
        
        if(k==0||i==n)
            return 0;
        if(dp[i][buy][k]!=-1)
            return dp[i][buy][k];
        if(buy){
            return dp[i][1][k]=max(-prices[i]+solve(i+1,n,0,prices,k),solve(i+1,n,1,prices,k));
        }
        else
        {
            return dp[i][0][k]=max(prices[i]+solve(i+1,n,1,prices,k-1),solve(i+1,n,0,prices,k));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,1,prices,2);
    }
};