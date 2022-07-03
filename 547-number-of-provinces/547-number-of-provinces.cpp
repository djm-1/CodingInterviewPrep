class Solution {
public:
    vector<int>parent;
    
    int find(int v)
    {
        if(parent[v]==-1)
            return v;
        return find(parent[v]);
    }
    
    
    void union_find(int u, int v){
        
        int x=find(u);
        int y=find(v);
        
        if(x!=y)
            parent[y]=x;
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        parent.resize(n,-1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1)
                {
                    union_find(i,j);
                }
            }
        }
        
        int count=0;
        for(auto x:parent){
            cout<<x<<" ";
            if(x==-1)
                count++;
        }
        
        return count;
    }
};