// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void dfs(vector<vector<int>>&adj, int i, string &ans,vector<bool>&visited){
        if(visited[i])
            return;
        visited[i]=true;
        for(auto x:adj[i])
        {
            if(!visited[x])
                dfs(adj,x,ans,visited);
        }
        
        ans.push_back(i+'a');
    }
    
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>adj(K);
        
        for(int i=0;i<N-1;i++)
        {
            int m=dict[i].size();
            int n=dict[i+1].size();
            
            for(int j=0;j<min(m,n);j++)
            {
                if(dict[i][j]!=dict[i+1][j])
                {
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        
        vector<bool>visited(K,false);
        
        string ans;
        for(int i=0;i<K;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,ans,visited);
            }
        }
        
        reverse(ans.begin(),ans.end());
        // for(int i=0;i<K;i++)
        // {
        //     for(auto x:adj[i])
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }
        // cout<<ans;
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends