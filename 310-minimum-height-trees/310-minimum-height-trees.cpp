class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        
        if(edges.size()==0)
            return {0};
        
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            degree[x[1]]++;
            degree[x[0]]++;
        }
        
        queue<int>q;
        
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        vector<vector<int>>level;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>res;
            while(sz--)
            {
                auto x=q.front();
            
                q.pop();
                
                res.push_back(x);
            
                for(auto v:adj[x])
                {
                    degree[v]--;
                    if(degree[v]==1)
                        q.push(v);
                }   
            }
            
            level.push_back(res);
        }
            
        
        return level[level.size()-1];
    }
};