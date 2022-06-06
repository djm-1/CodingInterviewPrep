// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long maximumSumSubarray(int K, vector<int> &Arr , int N){
      // code here 
        long long int sum=0;
        for(int i=0;i<K;i++)
            sum+=Arr[i];
        int start=0;
        //int end=K;
        long long int max_sum=sum;
        for(int end=K;end<N;end++)
        {
            sum+=Arr[end]-Arr[start];
            start++;
            max_sum=max(sum,max_sum);
        }
        return max_sum;
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