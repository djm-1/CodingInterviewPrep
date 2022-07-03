class Solution {
public:
    vector<int>parent;
    
    int find_par(int v){
        if(parent[v]==-1)
            return v;
        return find_par(parent[v]);
    }
    
    
    bool union_find(int u,int v){
        int x=find_par(u);
        int y=find_par(v);
        if(x==y)
            return true;
        parent[y]=x;
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        parent.resize(n+1,-1);
        for(auto x:edges){
           if(union_find(x[0],x[1]))
               return x;
        }
        
        return {};
    }
};