// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool>visited(V,false);
        int province=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i]){
                
                province++;
                queue<int>Q;
                Q.push(i);
                while(!Q.empty()){
                    int top=Q.front();
                    visited[top]=true;
                    Q.pop();
                    for(int j=0;j<adj[top].size();j++)
                    {
                        if(adj[top][j]==1 && !visited[j])
                        {
                            Q.push(j);
                        }
                    }
                }
            }
        }
        return province;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends