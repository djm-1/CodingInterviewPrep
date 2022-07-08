class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x:stones)
            pq.push(x);
        
        while(!pq.empty() && pq.size()>=2)
        {
            int fir=pq.top();
            pq.pop();
            int sec=pq.top();
            pq.pop();
            
            if(fir>sec)
                pq.push(fir-sec);
        }
        
        if(pq.empty())
            return 0;
        else
            return pq.top();
    }
};