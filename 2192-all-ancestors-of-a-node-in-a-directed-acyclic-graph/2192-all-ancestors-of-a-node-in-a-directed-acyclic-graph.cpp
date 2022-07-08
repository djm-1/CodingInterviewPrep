class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>ans(n),adj(n);
        vector<int>indegree(n,0);
        vector<set<int>>s(n);
        for(auto x:edges)
        {
            indegree[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        
        queue<int>Q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }    
        
        while(!Q.empty()){
            int v=Q.front();
            Q.pop();
            
            for(auto x:adj[v])
            {
                indegree[x]--;
                
                for(auto y:s[v])
                    s[x].insert(y);
                
                s[x].insert(v);
                
                if(indegree[x]==0)
                    Q.push(x);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto x:s[i])
                ans[i].push_back(x);
        }
        return ans;
    }
};