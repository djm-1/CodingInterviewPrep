class Solution {
public:
    int mod=1e9+7;
    int dp[5005][7][20];
    
    //dp(i,x,len)
    
    int solve(int roll, int last, int len, vector<int>& rollMax){
        
        if(roll==0)
            return 1;
        
        if(last>=0 && dp[roll][last][len]!=-1)
            return dp[roll][last][len];
        
        int ans=0;
        for(int val=1;val<=6;val++)
        {
            if(val==last && len==rollMax[last-1]) continue;
            else
            {
                ans=(ans+solve(roll-1,val,val==last?len+1:1,rollMax))%mod;
            }
        }
        
        if(last>=0) dp[roll][last][len]=ans;
        return ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,rollMax);
    }
};