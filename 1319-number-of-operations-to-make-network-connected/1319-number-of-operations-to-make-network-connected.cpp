class Solution {
public:
    vector<int>parent;
    
    int find(int v)
    {
        if(parent[v]==-1)
            return v;
        return parent[v]=find(parent[v]);
    }
    
    void union_find(int u, int v){
        int x=find(u);
        int y=find(v);
        if(x!=y)
            parent[y]=x;
    }
    
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables=connections.size();
        if(cables<n-1)
            return -1;
        parent.resize(n,-1);
        
        for(int i=0;i<cables;i++)
        {
            union_find(connections[i][0],connections[i][1]);
        }
        
        int count=0;
        
    
        for(int i=0;i<n;i++)
            if(parent[i]==-1)
                count++;
        
        return count-1;
    }
};