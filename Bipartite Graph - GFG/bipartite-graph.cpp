// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool checkBipartite(vector<int>&visited,vector<int>adj[],int source){
        
        
        for(auto x:adj[source])
        {
            if(visited[x]==-1)
            {
                visited[x]=1-visited[source];
                if(!checkBipartite(visited,adj,x))
                    return false;
                
            }
            else if(visited[x]==visited[source])
                return false;
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