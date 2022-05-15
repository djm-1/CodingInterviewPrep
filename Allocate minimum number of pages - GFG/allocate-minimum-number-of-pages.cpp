// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[],int N, int M, int target){
        // initially allocated to 1 student, 0 pages
        int stu=1,pages=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]>target)return false;
            else{
                if(A[i]+pages<=target)
                    pages+=A[i];
                else
                {
                    //new student added
                    stu++;
                    //give him these pages
                    pages=A[i];
                }
            }
        }
        
        if(stu>M)
            return false;
        else
            return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int lo=*min_element(A,A+N);
        int hi=0;
        for(int i=0;i<N;i++)
            hi+=A[i];
            
        int ans=-1;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(isPossible(A,N,M,mid))
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends