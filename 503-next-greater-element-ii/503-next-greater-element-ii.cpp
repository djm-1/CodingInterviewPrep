class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        
        stack<int>s;
        for(int i=0;i<2*n;i++)
        {
            if(s.empty()){
                s.push(i);
            }
            else
            {
                while(!s.empty() && nums[s.top()]<nums[i])
                {
                    ans[s.top()%n]=nums[i%n];
                    s.pop();
                }
                s.push(i);
            }
        }
        return ans;
    }
};