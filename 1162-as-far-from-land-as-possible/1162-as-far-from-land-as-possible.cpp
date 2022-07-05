class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int maxi=-1;
        int m=grid.size();
        int n=grid[0].size();
        int dist=0;
        queue<pair<int,int>>Q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    Q.push({i,j});
                }
            }
        }
        
        
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        
        while(!Q.empty()){
            int sz=Q.size();
            for(int i=0;i<sz;i++)
            {
                auto v=Q.front();
                Q.pop();
                for(int j=0;j<4;j++)
                {
                    int x=v.first+dir[j][0];
                    int y=v.second+dir[j][1];
                    
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0){
                        maxi=max(maxi,dist);
                        grid[x][y]=1;
                        Q.push({x,y});
                    }
                }
            }
            dist++;
        }
        
        return maxi==-1?-1:maxi+1;
    }
};