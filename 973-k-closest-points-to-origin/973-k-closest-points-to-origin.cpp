class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>Q;
        for(auto x:points)
        {
            int dist=x[0]*x[0]+x[1]*x[1];
            Q.push({dist,x});
            if(Q.size()>k)
                Q.pop();
        }
        
        vector<vector<int>>ans;
        while(!Q.empty()){
            auto x=Q.top();
            ans.push_back(x.second);
            Q.pop();
        }
        
        return ans;
    }
};