class KthLargest {
public:
    priority_queue<int>Q;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        for(auto x:nums)
        {
            Q.push(-x);
            if(Q.size()>k)
                Q.pop();
        }
    }
    
    int add(int val) {
        Q.push(-val);
            if(Q.size()>sz)
                Q.pop();
        return -Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */