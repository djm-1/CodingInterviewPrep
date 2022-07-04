class Solution {
public:
    
    int dfs(int head, vector<vector<int>>&adj, vector<int>&time){
        if(adj[head].size()==0)
            return 0;
        int ans=0;
        for(auto x:adj[head])
        {
            ans=max(ans,dfs(x,adj,time));
        }
        return ans+=time[head];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        
        return dfs(headID,adj,informTime);
    }
};