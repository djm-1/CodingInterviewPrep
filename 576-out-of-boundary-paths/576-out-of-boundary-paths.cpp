class Solution {
public:
    uint dp[100][100][100];
    uint mod=1e9+7;
    int solve(int m, int n, int maxMove, int startRow, int startColumn){
        
        if(maxMove<0)
            return 0;
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n)
            return 1;
        
        if(dp[startRow][startColumn][maxMove]!=-1)
            return dp[startRow][startColumn][maxMove];
        
        return dp[startRow][startColumn][maxMove]=(solve(m,n,maxMove-1,startRow-1,startColumn)%mod+solve(m,n,maxMove-1,startRow+1,startColumn)%mod+solve(m,n,maxMove-1,startRow,startColumn-1)%mod+solve(m,n,maxMove-1,startRow,startColumn+1)%mod)%mod;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};