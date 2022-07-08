class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int>mp;
        for(auto x:s)
            mp[x]++;
        priority_queue<pair<int,char>>pq;
        string ans;
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }
        
        while(!pq.empty())
        {
            auto x=pq.top();
            while(x.first--)
                ans.push_back(x.second);
            pq.pop();
        }
        
        return ans;
    }
};