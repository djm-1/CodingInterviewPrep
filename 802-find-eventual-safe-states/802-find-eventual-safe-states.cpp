class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n=graph.size();
      
        vector<int>outdegree(n,0);
        
        vector<vector<int>>parent(n);
        
        for(int i=0;i<n;i++)
        {
            outdegree[i]=graph[i].size();
            
            for(auto x:graph[i])
            {
                parent[x].push_back(i);
            }
        }
        
        queue<int>Q;
        
        for(int i=0;i<n;i++)
            if(outdegree[i]==0)
                Q.push(i);
        
        while(!Q.empty()){
            int v=Q.front();
            Q.pop();
            
            for(auto x:parent[v])
            {
                outdegree[x]--;
                if(outdegree[x]==0)
                    Q.push(x);
            }
            
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(outdegree[i]==0)
                ans.push_back(i);
        }
        
        return ans;
    }
};