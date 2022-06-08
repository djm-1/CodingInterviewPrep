class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>DQ;
        int start=0,end=0;
        for(end=0;end<k;end++)
        {
            while(!DQ.empty() && DQ.back()<nums[end])
                DQ.pop_back();
            DQ.push_back(nums[end]);
        }
        
        ans.push_back(DQ.front());
        while(end<nums.size()){
            
            if(!DQ.empty() && DQ.front()==nums[start])
                DQ.pop_front();
            start++;
            
            while(!DQ.empty() && DQ.back()<nums[end])
                DQ.pop_back();
            DQ.push_back(nums[end]);
            end++;
            
            ans.push_back(DQ.front());
        }
        
        return ans;
    }
};