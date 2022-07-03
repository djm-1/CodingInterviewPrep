class Solution {
public:
    int dp[500][500];
    
    
    int dfs(int i, int j, vector<vector<int>>&grid, int m ,int n){
           
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        vector<vector<int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int k=0;k<4;k++)
        {
            int x=i+d[k][0];
            int y=j+d[k][1];
            
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]<grid[i][j])
                ans=max(ans,dfs(x,y,grid,m,n));
        }
        
        return dp[i][j]=ans+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        
        int m=grid.size();
        int n=grid[0].size();
        
        int max_path=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                int ans=dfs(i,j,grid,m,n);
                max_path=max(max_path,ans);
            }
        }
        
        return max_path;
    }
};