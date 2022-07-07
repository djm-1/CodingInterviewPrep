class Solution {
public:
    
    vector<int>parent;
    vector<int>rank;
    
    int find(int v)
    {
        if(parent[v]==v)
            return v;
        return parent[v]=find(parent[v]);
    }
    
    
    bool union_find(int u, int v){
        int a=find(u);
        int b=find(v);
        
        if(a==b)
            return false;
        
        if(rank[b]>rank[a])
            swap(a,b);
        else if(rank[a]==rank[b])
            rank[a]++;
        parent[b]=a;
        return true;
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        rank.resize(n,0);
        
        vector<pair<int,pair<int,int>>>edges;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dis,{i,j}});
                edges.push_back({dis,{j,i}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int weight=0;
        for(int i=0;i<edges.size();i++){
            int wt=edges[i].first;
            int u=edges[i].second.first;
            int v=edges[i].second.second;
            
            if(union_find(u,v))
                weight+=wt;
        }
        
        return weight;
    }
};