class Solution {
public:
    
    void dfs(vector<vector<int>>&grid, int i, int j, int m, int n){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||grid[i][j]==-1)
            return;
        
        grid[i][j]=-1;
        dfs(grid,i-1,j,m,n);
        dfs(grid,i+1,j,m,n);
        dfs(grid,i,j-1,m,n);
        dfs(grid,i,j+1,m,n);
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||i==m-1||j==0||j==n-1) && grid[i][j]==1)
                    dfs(grid,i,j,m,n);
            }
        }
        
        
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    count++;
            }
        }
        
        return count;
    }
};