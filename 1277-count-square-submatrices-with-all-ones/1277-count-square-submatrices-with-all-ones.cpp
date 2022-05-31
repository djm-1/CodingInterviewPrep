class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int dp[m][n];
        int sum=0;
        
        //memset(dp,1,sizeof(dp));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    dp[i][j]=0;
                else if(i==0||j==0)
                    dp[i][j]=1;
                else if(i>=1 && j>=1)
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                sum+=dp[i][j];
            }
        }
        
        return sum;
    }
};