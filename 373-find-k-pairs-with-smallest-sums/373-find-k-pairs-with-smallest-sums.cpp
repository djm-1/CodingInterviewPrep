class Solution {
public:
    typedef pair<int,vector<int>>pi;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        
        for(int i=0;i<nums2.size();i++)
        {
            pq.push({nums1[0]+nums2[i],{0,i}});
        }
        
        vector<vector<int>>res;
        while(k-- && !pq.empty())
        {
            auto x=pq.top().second;
            pq.pop();
            res.push_back({nums1[x[0]],nums2[x[1]]});
            if(x[0]<nums1.size()-1)
            {
                pq.push({nums1[x[0]+1]+nums2[x[1]],{x[0]+1,x[1]}});
            }
            
        }
        
        return res;
    }
};