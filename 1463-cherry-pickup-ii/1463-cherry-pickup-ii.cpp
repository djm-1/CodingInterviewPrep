class Solution {
public:
    int dp[100][100][100];
    
    int solve(vector<vector<int>>&grid, int m, int n, int r, int c1, int c2){
        if(c1<0||c1>=n||c2<0||c2>=n)
            return INT_MIN;
        
        if(r==m-1){
            if(c1==c2)
                return grid[r][c1];
            else
                return grid[r][c1]+grid[r][c2];
        }
        
        if(dp[r][c1][c2]!=-1)
            return dp[r][c1][c2];
        
        int maxi=INT_MIN;
        for(int dr1=-1;dr1<=1;dr1++)
        {
            for(int dr2=-1;dr2<=1;dr2++){
                
                int ans;
                if(c1==c2)
                    ans=grid[r][c1];
                else
                    ans=grid[r][c1]+grid[r][c2];
                
                ans+=solve(grid,m,n,r+1,c1+dr1,c2+dr2);
                maxi=max(maxi,ans);
            }
        }
        
        return dp[r][c1][c2]=maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        
        int m=grid.size();
        int n=grid[0].size();
        
        return solve(grid,m,n,0,0,n-1);
        
    }
};