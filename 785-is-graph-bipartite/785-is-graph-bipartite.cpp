class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        queue<int>Q;
        
        vector<int>coloring(n,0);
        
        
        for(int i=0;i<n;i++)
        {
            if(coloring[i]==0)
            {
                coloring[i]=1;
                Q.push(i);

                while(!Q.empty()){
                int v=Q.front();
                Q.pop();
                for(auto x:graph[v])
                {
                    if(coloring[x]==coloring[v])
                        return false;
                    if(coloring[x]==0)
                    {
                        coloring[x]=3-coloring[v];
                        Q.push(x);
                    }
                }
            }
            }
        }
        
        return true;
    }
};