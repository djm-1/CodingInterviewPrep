class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int fresh=0;
        queue<pair<int,int>>Q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                else if(grid[i][j]==2)
                {
                    Q.push({i,j});
                }
            }
        }
        
        int dir[]={0,1,0,-1,0};
        int ans=0;
        while(!Q.empty()){
            int size=Q.size();
            while(size--)
            {
                auto x=Q.front();
                Q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=x.first+dir[i];
                    int c=x.second+dir[i+1];

                    if(r>=0 && c>=0 && r<m && c<n && grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        Q.push({r,c});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if(fresh>0)
            return -1;
        if(ans==0)
            return 0;
        return ans-1;
    }
};