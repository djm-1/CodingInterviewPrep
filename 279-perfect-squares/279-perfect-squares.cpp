class Solution {
public:
    int numSquares(int n) {
        int root=sqrt(n);
        
        
        int dp[n+1];
        memset(dp,1e9+7,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=root;j++){
                if(i>=j*j)
                    dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        // for(auto x:dp)
        //     cout<<x<<" ";
        return dp[n];
    }
};