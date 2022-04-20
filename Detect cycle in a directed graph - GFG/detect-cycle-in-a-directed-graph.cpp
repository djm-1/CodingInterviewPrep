// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCycle(vector<int>adj[],vector<int>&visited,vector<int>&dfsvisit,int node){
        
        visited[node]=1;
        dfsvisit[node]=1;
        for(auto x:adj[node]){
            if(visited[x]==0)
            {
                if(checkCycle(adj,visited,dfsvisit,x))
                    return true;
            }
            else if(dfsvisit[x]==1)
                return true;
        }
        dfsvisit[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V+1,0);
        vector<int>dfsvisit(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
                if(checkCycle(adj,visited,dfsvisit,i))
                    return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends