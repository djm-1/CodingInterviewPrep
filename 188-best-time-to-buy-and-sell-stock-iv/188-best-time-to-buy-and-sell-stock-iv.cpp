class Solution {
public:
    
    int dp[2000][2][500];
    
    int solve(int i, int buy, int n, vector<int>&prices, int k){
        if(i==n||k==0)
            return 0;
        
        if(dp[i][buy][k]!=-1)
            return dp[i][buy][k];
        
        if(buy==1){
            
            return dp[i][1][k]=max(-prices[i]+solve(i+1,0,n,prices,k),solve(i+1,1,n,prices,k));
        }
        else
        {
            return dp[i][0][k]=max(prices[i]+solve(i+1,1,n,prices,k-1),solve(i+1,0,n,prices,k));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,n,prices,k);
    }
};