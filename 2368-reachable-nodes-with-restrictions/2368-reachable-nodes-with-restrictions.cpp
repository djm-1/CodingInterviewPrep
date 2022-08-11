class Solution {
public:
    
    void dfs(int node, vector<bool>&visited, vector<int>adj[],set<int>&s)
    {
        if(visited[node]||s.find(node)!=s.end())
            return;
        visited[node]=true;
        for(auto x:adj[node])
        {
            dfs(x,visited,adj,s);
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool>visited(n,false);
        
        set<int>s;
        for(auto x:restricted)
            s.insert(x);
        
        
        vector<int>adj[n];
        
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        dfs(0,visited,adj,s);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                cnt++;
        }
        
        return cnt;
    }
};