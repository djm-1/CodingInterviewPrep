// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    
    public:
    typedef long long ll;
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if(n==1)
            return 0;
        
        priority_queue<ll>pq;
        ll cost=0;
        for(int i=0;i<n;i++)
            pq.push(-arr[i]);
        
        // atleast 2 elements must be there in queue
        // at last step only 1 element will be remaining
        
        while(!pq.empty() && pq.size()>=2)
        {
            ll first=pq.top();
            pq.pop();
            ll second=pq.top();
            pq.pop();
            
            ll sum=first+second;
            cost+=(-sum);
            
            pq.push(sum);
        }
        
        return cost;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends