class Solution {
public:
    int dp[1000][1000];
    
    int solve(vector<int>&cuts, int left, int right){
        
        if(right<=left+1)
            return 0;
        if(dp[left][right]!=-1)
            return dp[left][right];
        int mini=INT_MAX;
        for(int k=left+1;k<right;k++)
        {
            mini=min(mini,solve(cuts,left,k)+solve(cuts,k,right)+cuts[right]-cuts[left]);
        }
        
        return dp[left][right]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        solve(cuts,0,cuts.size()-1);
        
        return dp[0][cuts.size()-1];
    }
};