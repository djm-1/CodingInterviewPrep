class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[1000][1000];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=word1.size();i++)
        {
            for(int j=0;j<=word2.size();j++)
            {
                if(i==0)
                    dp[i][j]=j;
                if(j==0)
                    dp[i][j]=i;
                if(i>=1 && j>=1)
                {
                    if(word1[i-1]==word2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        int insertion=dp[i][j-1];
                        int deletion=dp[i-1][j];
                        int replace=dp[i-1][j-1];
                        
                        dp[i][j]=1+min(insertion,min(deletion,replace));
                    }
                }
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};