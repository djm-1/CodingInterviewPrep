class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        // dp[0]=0;
        // dp[1]=0;
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++){
                dp[i]=max(max(dp[i],j*(i-j)),dp[i-j]*j);
            }
        }
        return dp[n];
    }
};