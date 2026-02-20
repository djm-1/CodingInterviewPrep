class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int dp[m][m];
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++)
        {
            int n=triangle[i].size();
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                else if(j==n-1)
                {
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                }
            }
        }
        int min_sum=INT_MAX;
        for(int i=0;i<m;i++)
        {
            min_sum=min(min_sum,dp[m-1][i]);
        }
        return min_sum;
    }
};