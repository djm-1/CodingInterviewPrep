class Solution {
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
public:
    typedef long long int ll;
    ll ans=0;
    ll mod=1000000007;
    ll dp[1001][1001];
    
    
    ll dfs(int i, int j, vector<vector<int>>&grid, int m, int n){
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        ll cnt=1;
        
        for(int k=0;k<4;k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            
            
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]<grid[i][j]){
                cnt=((cnt%mod)+(dfs(x,y,grid,m,n)%mod))%mod;
            }
        }
        
        return dp[i][j]=cnt%mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=(ans%mod+dfs(i,j,grid,m,n)%mod)%mod;
            }
        }
        
        return ans;
    }
};