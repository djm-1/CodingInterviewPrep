class Solution {
public:
    typedef pair<int,int>pint;
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        priority_queue<pint,vector<pint>,greater<pint>>minheap;
        priority_queue<pint>maxheap;
        
        for(int i=0;i<capital.size();i++)
        {
            minheap.push({capital[i],profit[i]});
            
        }
        
        
        for(int i=0;i<k;i++)
        {
            while(!minheap.empty() && minheap.top().first<=w)
            {
                auto x=minheap.top();
                maxheap.push({x.second,x.first});
                minheap.pop();
            }
            
            if(maxheap.empty())
                break;
            else
            {
                w+=maxheap.top().first;
                maxheap.pop();
            }
        }
        
        return w;
    }
};