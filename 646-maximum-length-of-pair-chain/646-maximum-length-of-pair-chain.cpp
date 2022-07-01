class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        
        int n=pairs.size();
        vector<int>dp(n);
        dp[0]=1;
        
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};