class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>um;
        int n=nums2.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()<nums2[i])
            {
                um[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!um[nums2[i]])
            {
                um[nums2[i]]=-1;
            }
        }
        
        vector<int>ans;
        for(auto x:nums1)
            ans.push_back(um[x]);
        return ans;
    }
};