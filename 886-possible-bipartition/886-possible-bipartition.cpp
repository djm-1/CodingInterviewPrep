class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>visited(n+1,0);
        
        vector<vector<int>>adj(n+1);
        
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        
        queue<int>Q;
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==0)
            {
                Q.push(i);
                visited[i]=1;
                while(!Q.empty()){
                    int v=Q.front();
                    Q.pop();

                    for(auto x:adj[v])
                    {
                        if(visited[x]==visited[v])
                            return false;
                        if(visited[x]==0)
                        {
                            visited[x]=3-visited[v];
                            Q.push(x);
                        }
                    }
                }
            }    
        }
        return true;
        
    }
};