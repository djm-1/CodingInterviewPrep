class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto x:s)
            mp[x]++;
        string ans;
        priority_queue<pair<int,char>>pq;
        
        for(auto x:mp)
            pq.push({x.second,x.first});
        
        while(pq.size()>1)
        {
            auto fir=pq.top();
            pq.pop();
            auto sec=pq.top();
            pq.pop();
            
            ans+=fir.second;
            ans+=sec.second;
            
            sec.first--,fir.first--;
            if(fir.first>0)
                pq.push(fir);
            if(sec.first>0)
                pq.push(sec);
        }
        
        if(!pq.empty())
        {
            if(pq.top().first>1)
                return "";
            else
                ans+=pq.top().second;
        }
        return ans;
    }
};