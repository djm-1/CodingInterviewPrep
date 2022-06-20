class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else
                {
                    if(s1[i-1]==s2[j-1])
                        dp[i][j]=dp[i-1][j-1]+(int)s1[i-1];
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        
        
        int sum=0;
        for(auto x:s1)
            sum+=(int)x;
        for(auto x:s2)
            sum+=(int)x;
        sum-=2*dp[m][n];
        return sum;
    }
};