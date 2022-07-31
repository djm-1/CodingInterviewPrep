class Solution {
public:
    
    unordered_map<string,bool>mp;
    
    int dp[500];
    
    int solve(string &s, int i)
    {
        if(i==s.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        string temp;
        for(int j=i;j<s.size();j++)
        {
            temp.push_back(s[j]);
            if(mp.find(temp)!=mp.end())
            {
                if(solve(s,j+1))
                    return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict)
            mp[x]=true;
        memset(dp,-1,sizeof(dp));
        return (bool)solve(s,0);
    }
};