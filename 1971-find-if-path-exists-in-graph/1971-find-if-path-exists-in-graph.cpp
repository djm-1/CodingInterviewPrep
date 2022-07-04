class Solution {
public:
    
    
    bool dfs(vector<vector<int>>&adj,vector<bool>&visited, int s, int d)
    {
        if(s==d)
            return true;
        visited[s]=true;
        for(auto x:adj[s])
        {
            if(!visited[x] && dfs(adj,visited,x,d))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool>visited(n,false);
        
        if(dfs(adj,visited,source,destination))
            return true;
        
        return false;
    }
};