class Solution {
public:
    int dp[1200][1200];
    
    int solve(string &s, int i, int j)
    {
        if(i>=j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j]=solve(s,i+1,j-1);
        
        return dp[i][j]=0;
    }
    
    
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        
        int count=0;
        int n=s.size();
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<=j;i++)
            {
                count+=solve(s,i,j);        
            }
        }
        
        return count;
    }
};