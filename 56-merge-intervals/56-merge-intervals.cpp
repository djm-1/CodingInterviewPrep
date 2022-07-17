class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        if(intervals.size()==0||intervals.size()==1)
            return intervals;
        for(auto x:intervals){
            if(merged.size()==0||merged.back()[1]<x[0])
                merged.push_back(x);
            else
            {
                merged.back()[1]=max(merged.back()[1],x[1]);
            }
        }
        
        return merged;
    }
};