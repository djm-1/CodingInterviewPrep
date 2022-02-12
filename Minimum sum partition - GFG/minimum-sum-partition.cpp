// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    /*
	    
	    if S is total sum, X is sum of one set, S-X will be sum of other set.
	    Hence, we need to minimize abs((S-X)-X)=abs(S-2*X)
	    For that, we need to find X closest to S/2.
	    if check for X values in [0,S/2] range... problem is solved.
	    Dynamic Programming problem similar to equal sum partition.
	    
	    */
	    
	    
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	   int target=sum/2;
	   bool dp[n+1][target+1];
	   
	   for(int i=0;i<=n;i++)
	    dp[i][0]=true;
	   for(int i=1;i<=target;i++)
	    dp[0][i]=false;
	    
	   for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=target;j++)
	       {
	           if(arr[i-1]>j)
	            dp[i][j]=dp[i-1][j];
	           else
	            dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	       }
	   }
	   
	   int mini=INT_MAX;
	   for(int i=0;i<=n;i++)
	   {
	       for(int j=0;j<=target;j++){
	           
	           if(dp[i][j])
	            mini=min(mini,abs(sum-2*j));
	       }
	   }
	   
	   return mini;
	   
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends