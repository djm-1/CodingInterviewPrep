class Solution {
public:
    static bool comp(const string &w1,const string &w2){
        return w1.size()<w2.size();
    }
    
    bool pre(string w1, string w2){
        if(w1.size()!=w2.size()+1)
            return false;
        int i=0,j=0;
        while(i<w1.size() && j<w2.size())
        {
            if(w1[i]==w2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        if(i==w1.size() && j==w2.size())
            return true;
        else if(j==w2.size())
            return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        
        int n=words.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pre(words[i],words[j]) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            
            if(dp[i]>maxi)
                maxi=dp[i];
        }
        
        return maxi;
    }
};