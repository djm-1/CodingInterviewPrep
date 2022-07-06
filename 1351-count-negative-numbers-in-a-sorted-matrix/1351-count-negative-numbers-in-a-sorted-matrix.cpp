class Solution {
public:
    int count=0;
    
    void dfs(int i, int j,vector<vector<int>>&grid){
        if(i<0||j<0||grid[i][j]>=0)
            return;
        count++;
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        grid[i][j]=-grid[i][j];
    }
    
    
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[m-1][n-1]>=0)
            return 0;
        dfs(m-1,n-1,grid);
        return count;
        
    }
};