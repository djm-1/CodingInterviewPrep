class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool>visited(n,false);
        
        queue<int>Q;
        Q.push(source);
        visited[source]=false;
        
        while(!Q.empty()){
            int val=Q.front();
            Q.pop();
            visited[val]=true;
            
            for(auto x:adj[val])
            {
                if(!visited[x])
                {
                    Q.push(x);
                }
            }
        }
        
        return visited[destination];
    }
};