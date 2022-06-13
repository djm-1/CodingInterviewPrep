class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366);
        int n=days.size();
        unordered_map<int,int>mp;
        for(auto x:days)
            mp[x]=1;
        dp[0]=0;
        for(int i=1;i<=365;i++)
        {
            dp[i]=dp[i-1];
            if(mp.find(i)!=mp.end())
            {
                dp[i]=min(dp[i-1]+costs[0],min(
                    dp[max(0,i-7)]+costs[1],
                    dp[max(0,i-30)]+costs[2]
                ));
            }
        }
        
        return dp[days[n-1]];
    }
};