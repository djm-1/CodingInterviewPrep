class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({ages[i],scores[i]});
        }
        
        
        sort(v.begin(),v.end());
        
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
            dp[i]=v[i].second;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i].second>=v[j].second && dp[j]+v[i].second>=dp[i])
                {
                    dp[i]=dp[j]+v[i].second;
                }
            }
        }
        for(auto x:dp)
            cout<<x<<" ";
        return *max_element(dp.begin(),dp.end());
    }
};