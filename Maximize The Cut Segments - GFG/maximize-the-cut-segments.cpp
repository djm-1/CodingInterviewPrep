// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        int dp[n+1][3];
        dp[0][0]=0,dp[0][1]=0,dp[0][2]=0;
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i][1]=dp[i][2]=INT_MIN;
            if(i>=x)
                dp[i][0]=max(dp[i-x][0],max(dp[i-x][1],dp[i-x][2]))+1;
            if(i>=y)
                dp[i][1]=max(dp[i-y][0],max(dp[i-y][1],dp[i-y][2]))+1;
            if(i>=z)
                dp[i][2]=max(dp[i-z][0],max(dp[i-z][1],dp[i-z][2]))+1;
        }
        return max(dp[n][0],max(dp[n][1],max(dp[n][2],0)));
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends