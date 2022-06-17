class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        vector<int>ans;
        for(auto x:prices)
            ans.push_back(x);
        
        stack<int>st;
        for(int i=0;i<prices.size();i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && prices[st.top()]>=prices[i])
                {
                    int idx=st.top();
                    st.pop();
                    ans[idx]=prices[idx]-prices[i];
                }
                st.push(i);
            }
        }
        
        return ans;
    }
};