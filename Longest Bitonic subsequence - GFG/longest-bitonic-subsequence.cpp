// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int>lis(n,1),rev_lis(n,1);
	    
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j])
	            {
	                lis[i]=max(lis[i],lis[j]+1);
	            }
	        }
	    }
	    
	    reverse(nums.begin(),nums.end());
	    
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j])
	            {
	                rev_lis[n-1-i]=max(rev_lis[n-1-i],rev_lis[n-1-j]+1);
	            }
	        }
	    }
	    
	    int maxi=1;
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,lis[i]+rev_lis[i]-1);
	    }
	    
	    return maxi;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends