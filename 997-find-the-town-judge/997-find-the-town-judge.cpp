class Solution {
public:
    int findJudge(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n+1);
        vector<bool>alone(n+1,true);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            alone[edges[i][0]]=false;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==n-1 && alone[i]==true)
                return i;
        }
        return -1;
    }
};