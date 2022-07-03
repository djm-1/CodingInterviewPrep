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
    
    bool equationsPossible(vector<string>& equations) {
        
        parent.resize(26,-1);
        
        int n=equations.size();
        
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')
            {
                union_find(equations[i][0]-'a',equations[i][3]-'a');
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!')
            {
                if(find(equations[i][0]-'a')==find(equations[i][3]-'a'))
                    return false;
            }
        }
        return true;
    }
};