class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>Q;
        for(auto x:nums)
            Q.push(x);
        for(int i=0;i<k-1;i++)
            Q.pop();
        return Q.top();
    }
};