// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int t[501][501];

class Solution{
public:
    
    bool is_palindrome(string &str,int i,int j){
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            
                i++,j--;
        }
        return true;
    }
    int solve(string &str, int i, int j){
        int mini=INT_MAX;
        if(i>=j||is_palindrome(str,i,j))
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        
        for(int k=i;k<j;k++)
        {
            int ans=solve(str,i,k)+solve(str,k+1,j)+1;
            mini=min(mini,ans);    
        }
        
        return t[i][j]=mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(t,-1,sizeof(t));
        int n=str.size();
        int ans=solve(str,0,n-1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends