class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>frq;
        for(auto x:nums)
            frq[x]++;
        
        priority_queue<pair<int,int>>PQ;
        for(auto x:frq)
        {
            PQ.push({-x.second,x.first});
            if(PQ.size()>k)
                PQ.pop();
        }
        
        vector<int>ans;
        while(!PQ.empty())
        {
            ans.push_back(PQ.top().second);
            PQ.pop();
        }
        return ans;
    }
};