class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>Q;
        for(auto x:nums)
        {
            Q.push(-x);
            if(Q.size()>k)
                Q.pop();
        }
        return -Q.top();
    }
};