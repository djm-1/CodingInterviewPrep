class Solution {
public:
    
    bool DetectCycle(int v, vector<int>&visited, vector<vector<int>>&adj){
        
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        visited[v]=1;
        for(auto x:adj[v])
        {
            if(DetectCycle(x,visited,adj))
                return true; 
        }
        visited[v]=2;
        return false;
    }
    
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        vector<int>visited(num,0);
        vector<vector<int>>adj(num);
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        
        
        for(int i=0;i<num;i++)
        {
            if(visited[i]==0 && DetectCycle(i,visited,adj))
                return false;
        }
        
        return true;
        
    }
};