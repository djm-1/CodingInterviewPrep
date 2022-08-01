class Solution {
public:
    int dp[50][50];
    
    int maxival(vector<int>&arr,int i, int j)
    {
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++)
            maxi=max(maxi,arr[k]);
        return maxi;
    }
    
    int solve(vector<int>&arr, int i, int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int sum=INT_MAX;
        for(int k=i;k<j;k++)
        {
            
            int ans=solve(arr,i,k)+solve(arr,k+1,j)+maxival(arr,i,k)*maxival(arr,k+1,j);
            sum=min(sum,ans);
        }
        
        return dp[i][j]=sum;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));    
        return solve(arr,0,n-1);
    }
};