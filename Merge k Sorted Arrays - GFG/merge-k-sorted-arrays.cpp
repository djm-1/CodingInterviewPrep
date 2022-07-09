// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    typedef pair<int,pair<int,int>>pi; 
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        vector<int>ans;
        for(int i=0;i<K;i++)
        {
            pq.push({arr[i][0],{i,0}});
        }
        
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            
            ans.push_back(x.first);
            int idx=x.second.second;
            int i=x.second.first;
            
            if(idx<arr[i].size()-1)
                pq.push({arr[i][idx+1],{i,idx+1}});
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends