class Solution {
public:
    
    void dfs(vector<int>adj[], vector<bool>&visited, int i,long long &count)
    {
        if(visited[i])
            return;
        visited[i]=true;
        count++;
        for(auto x:adj[i])
        {
            dfs(adj,visited,x,count);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[100009];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        long long comps=0;
        vector<bool>visited(n,false);
        
        //vector<long long>store;
        
        long long ans=((long long)n*(n-1))/2;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            { 
                long long count=0;
                dfs(adj,visited,i,count);
                ans-=(count*(count-1))/2;
            }
        }
        
        
        
        
        return ans;
    }
};