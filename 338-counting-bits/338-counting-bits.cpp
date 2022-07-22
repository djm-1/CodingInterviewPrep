class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        int lastpow=1;
        if(n>=1)
        {
            for(int i=1;i<=n;i++)
        {
            if(!(i&(i-1)))
            {
                lastpow=i;
                dp[i]=1;
            }
            else
                dp[i]=1+dp[i-lastpow];
        }    
        }
        
        return dp;
    }
};