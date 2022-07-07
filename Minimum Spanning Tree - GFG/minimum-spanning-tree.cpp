// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Edge{
        public:
        int u,v,w;
        Edge(int u, int v, int w){
           this->u=u;
           this->v=v;
           this->w=w;
        }
	};
class Solution
{
	public:
	vector<int>parent;
	vector<int>rank;
	
	int find_parent(int v){
	    if(v==parent[v])
	        return v;
	   return parent[v]=find_parent(parent[v]);
	}
	
	bool union_find(int u, int v)
	{
	    int a=find_parent(u);
	    int b=find_parent(v);
	    
	    if(a==b)
	        return false;
	    else
	    {
	        if(rank[b]>rank[a])
	            swap(a,b);
	        else if(rank[a]==rank[b])
	            rank[a]++;
	        parent[b]=a;
	        return true;
	    }
	}
	
	
	static bool comp(Edge &a, Edge &b){
	    return b.w>a.w;
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        
        vector<Edge>edges;
        
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                edges.push_back(Edge(i,x[0],x[1]));
            }
        }
        
        sort(edges.begin(),edges.end(),comp);
        int ans=0;
        for(int i=0;i<edges.size();i++)
        {
            if(union_find(edges[i].u,edges[i].v))
                ans+=edges[i].w;
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends