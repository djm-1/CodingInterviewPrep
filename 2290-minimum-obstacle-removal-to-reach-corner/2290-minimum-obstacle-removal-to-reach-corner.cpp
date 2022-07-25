class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        deque<pair<int,int>>dq;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        
        dist[0][0]=0;
        
        dq.push_back({0,0});
        
        vector<vector<int>>dir={
            {-1,0},
            {1,0},
            {0,1},
            {0,-1}
        };
        
        while(!dq.empty())
        {
            auto x=dq.front();
            
            dq.pop_front();
            
            for(int i=0;i<4;i++)
            {
                int r=x.first+dir[i][0];
                int c=x.second+dir[i][1];
                
                int wt=grid[x.first][x.second];
                
                if(r>=0 && r<m && c>=0 && c<n)
                {
                    if(dist[x.first][x.second]+wt<dist[r][c])
                    {
                        dist[r][c]=dist[x.first][x.second]+wt;
                        
                        if(wt==0)
                        {
                            dq.push_front({r,c});
                        }
                        else
                        {
                            dq.push_back({r,c});
                        }
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};