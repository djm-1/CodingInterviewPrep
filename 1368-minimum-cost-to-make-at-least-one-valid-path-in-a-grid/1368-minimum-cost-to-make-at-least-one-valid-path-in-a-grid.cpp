class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        deque<pair<int,int>>Q;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        
        dist[0][0]=0;
        
        Q.push_back({0,0});
        
        vector<vector<int>>dir={
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        
        
        while(!Q.empty()){
            auto v=Q.front();
            Q.pop_front();
            for(int d=0;d<4;d++)
            {
                int x=v.first+dir[d][0];
                int y=v.second+dir[d][1];
                
                if(x>=0 && x<m && y>=0 && y<n)
                {
                    int wt=grid[v.first][v.second]==d+1?0:1;
                    if(dist[v.first][v.second]+wt<dist[x][y])
                    {
                        dist[x][y]=dist[v.first][v.second]+wt;
                        if(wt==0)
                        {
                            Q.push_front({x,y});
                        }
                        else
                        {
                            Q.push_back({x,y});
                        }
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};