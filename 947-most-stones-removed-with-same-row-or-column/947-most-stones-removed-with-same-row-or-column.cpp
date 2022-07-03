class Solution {
public:
    vector<int>parent;
    
    int find(int v){
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
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        parent.resize(n,-1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                {
                    union_find(i,j);
                }
            }
        }
        
        int comps=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
                comps++;
        }
        
        
        
        return n-comps;
    }
};