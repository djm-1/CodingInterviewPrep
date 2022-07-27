class Solution {
public:
    string removeDuplicates(string s) {
     stack<char>st;
        
    for(auto x:s)
    {
        if(st.empty())
        {
            st.push(x);
        }
        else
        {
            if(x==st.top())
                st.pop();
            else
                st.push(x);
        }
    }
        string ans;
        while(!st.empty())
        {
            char c=st.top();
            st.pop();
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};