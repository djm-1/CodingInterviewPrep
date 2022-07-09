class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto x:tasks)
            mp[x]++;
        
        priority_queue<pair<int,char>>pq;
        
        for(auto x:mp)
            pq.push({x.second,x.first});
        
        int idle=0;
        while(!pq.empty())
        {
            int count=0;
            vector<pair<int,char>>vec;
            while(!pq.empty() && count<=n)
            {
                auto x=pq.top();
                pq.pop();
                vec.push_back(x);
                count++;
            }
            
            for(auto x:vec)
            {
                x.first--;
                if(x.first>0)
                    pq.push(x);
            }
            
            if(pq.empty())
                idle+=vec.size();
            else
                idle+=n+1;
        }
        
        return idle;
        
    }
};