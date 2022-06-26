class Solution {
public:
    int maxArea=0;
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &area){
        
        int m=grid.size();
        int n=grid[0].size();
        
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||grid[i][j]==-1)
            return;
        
        area+=1;
        
        grid[i][j]=-1;
        dfs(grid,i-1,j,area);
        dfs(grid,i,j-1,area);
        dfs(grid,i+1,j,area);
        dfs(grid,i,j+1,area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    dfs(grid,i,j,area);
                    maxArea=max(maxArea,area);
                }
            }
        }
        
        return maxArea;
    }
};