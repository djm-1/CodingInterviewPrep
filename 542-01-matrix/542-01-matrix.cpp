class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>Q;
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    Q.push({i,j});
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }
        
        int dist=0;
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        
        while(!Q.empty())
        {
            auto v=Q.front();
            Q.pop();
            for(int i=0;i<4;i++)
            {
                int x=v.first+dir[i][0];
                int y=v.second+dir[i][1];
                
                if(x>=0 && x<m && y>=0 && y<n && mat[x][y]==-1)
                {
                    mat[x][y]=mat[v.first][v.second]+1;
                    Q.push({x,y});
                }
            }    
        }
        
        return mat;
    }
};