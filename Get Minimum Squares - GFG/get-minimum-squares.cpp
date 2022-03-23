// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	     
	    vector<int>dp(n+1);
	    dp[0]=0;
	    dp[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        dp[i]=i;
	        for(int j=0;j*j<=i;j++)
	        {
	            dp[i]=min(dp[i],dp[i-j*j]+1);   
	        }
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends