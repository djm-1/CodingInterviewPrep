class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        
        int visited[m][n][k+1];
        
        memset(visited,-1,sizeof(visited));
        
        visited[0][0][0]=0;
        
        queue<vector<int>>q;
        q.push({0,0,0});
        
        vector<vector<int>>dir={
            {-1,0},
            {1,0},
            {0,1},
            {0,-1}
        };
        
        int level=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                
                if(x[0]==m-1 && x[1]==n-1)
                        return level;
                
                
                if(grid[x[0]][x[1]]==1)
                    x[2]++;
                
                for(int i=0;i<4;i++)
                {
                    int r=x[0]+dir[i][0];
                    int c=x[1]+dir[i][1];

                    
                    if(r>=0 && r<m && c>=0 && c<n)
                    {
                        if(x[2]<=k && visited[r][c][x[2]]!=0)
                        {
                            visited[r][c][x[2]]=0;
                            q.push({r,c,x[2]});
                        }
                            
                    }
                }
                
                
            }
            
            level++;
        }
        
        return -1;
    }
};