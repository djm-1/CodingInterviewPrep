class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return false;
        vector<int>mini(n);
        mini[0]=nums[0];
        
        for(int i=1;i<n;i++)
            mini[i]=min(mini[i-1],nums[i]);
        
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                if(mini[st.top()]!=nums[st.top()])
                    return true;
                st.pop();
            }
                
            st.push(i);
            
        }
        for(auto x:mini)
            cout<<x<<" ";
        return false;
    }
};