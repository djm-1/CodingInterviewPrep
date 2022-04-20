// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool checkBipartite(vector<int>&visited,vector<int>adj[],int source){
        queue<int>q;
        visited[source]=0;
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node])
            {
                if(visited[x]==-1)
                {
                    visited[x]=1-visited[node];
                    q.push(x);
                }
                else if(visited[x]==visited[node])
                    return false;
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>visited(V+1,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	       if(visited[i]==-1) 
	           if(!checkBipartite(visited,adj,i))
	                return false;
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends