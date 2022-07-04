class Solution {
public:
    
    
    void dfs(int i,int j, int m, int n, vector<vector<int>>&grid){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==1)
            return;
        grid[i][j]=1;
        dfs(i-1,j,m,n,grid);
        dfs(i+1,j,m,n,grid);
        dfs(i,j-1,m,n,grid);
        dfs(i,j+1,m,n,grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||i==m-1||j==0||j==n-1)
                    dfs(i,j,m,n,grid);
            }
        }
        
        int count=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    dfs(i,j,m,n,grid);
                }
            }
        }
        
        return count;
    }
};