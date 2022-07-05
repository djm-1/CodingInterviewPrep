class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int dist=0;
        
        queue<pair<int,int>>Q;
        if(grid[0][0]==0){
            Q.push({0,0});
            grid[0][0]=1;
            dist++;
        }    
        
        vector<vector<int>>dir={
            {-1,0},
            {1,0},
            {0,1},
            {0,-1},
            {1,1},
            {1,-1},
            {-1,1},
            {-1,-1}
        };
        
        
        while(!Q.empty()){
            int sz=Q.size();
            for(int i=0;i<sz;i++)
            {
                auto v=Q.front();
                Q.pop();
                if(v.first==n-1 && v.second==n-1)
                    return dist;
                for(int j=0;j<8;j++){
                    int x=v.first+dir[j][0];
                    int y=v.second+dir[j][1];
                    
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0)
                    {
                        grid[x][y]=1;
                        Q.push({x,y});
                    }
                }
        
            }
            dist++;
        }
        
        return -1;
    }
};