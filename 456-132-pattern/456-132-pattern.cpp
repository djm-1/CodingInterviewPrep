class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int>st;
        int n=nums.size(); 
        if(n<3)
            return false;
        vector<int>mini(n);
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            mini[i]=min(mini[i-1],nums[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && nums[st.top()]<=nums[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    if(mini[st.top()]!=nums[st.top()] && mini[st.top()]<nums[i])
                        return true;
                }
                st.push(i);
            }
        }
        return false;
    }
};