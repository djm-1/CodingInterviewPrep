class Solution {
public:
    vector<int>parent;
    
    int find_par(int v){
        if(parent[v]==v)
            return v;
        else
            return parent[v]=find_par(parent[v]);
    }
    
    
    void union_find(int u, int v){
        parent[find_par(u)]=find_par(v);    
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        parent.resize(n);
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    union_find(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                count++;
        }
        return count;
    }
};