class Solution {
public:
    
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        uint dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
                if(i>0 && j>0)
                {
                    if(s[i-1]==t[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    }
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};