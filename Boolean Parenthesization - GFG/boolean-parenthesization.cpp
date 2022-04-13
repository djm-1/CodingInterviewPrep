// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[500][500][2];
class Solution{
public:
int solve(string &str, int i,int j,bool check){
    if(i>j)
        return 0;
    if(i==j)
    {
        if(check)
            return str[i]=='T';
        else
            return str[i]=='F';
    }
    if(dp[i][j][check]!=-1)
        return dp[i][j][check];
    
    int count=0;
    for(int k=i+1;k<j;k+=2){
        
        int lt=solve(str,i,k-1,true);
        int rt=solve(str,k+1,j,true);
        int lf=solve(str,i,k-1,false);
        int rf=solve(str,k+1,j,false);
        if(str[k]=='&')
        {
            if(check)
                count+=lt*rt;
            else
                count+=lt*rf+lf*rt+lf*rf;
        }
            
        if(str[k]=='|')
        {
            if(check)
                count+=lt*rt+lf*rt+lt*rf;
            else
                count+=lf*rf;
        }
        
        if(str[k]=='^')
        {
            if(check)
                count+=lt*rf+lf*rt;
            else
                count+=lt*rt+lf*rf;
        }
    }
    return dp[i][j][check]=count%1003;
}
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        bool check=true;
        return solve(S,0,N-1,check);    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends