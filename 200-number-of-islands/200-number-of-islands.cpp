class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j){
        
        if(i<0 || i>=m || j<0 || j>=n)
            return;
        if(grid[i][j]=='0'||grid[i][j]=='2')
            return;
        
        grid[i][j]='2';
        dfs(grid,m,n,i-1,j);
        dfs(grid,m,n,i,j-1);
        dfs(grid,m,n,i+1,j);
        dfs(grid,m,n,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int island=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    island++;
                    dfs(grid,m,n,i,j);
                }
                    
            }
        }
        
        return island;
    }
};