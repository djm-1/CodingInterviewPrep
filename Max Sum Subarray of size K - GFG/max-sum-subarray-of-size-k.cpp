// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<K;i++)
            sum+=Arr[i];
        maxi=max(maxi,sum);
        for(int i=K-1;i<N-1;i++)
        {
            sum=sum-Arr[i-K+1]+Arr[i+1];
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends