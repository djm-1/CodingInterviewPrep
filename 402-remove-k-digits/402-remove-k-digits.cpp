class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        if(k>=n)
            return "0";
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(num[i]);
            }
            else
            {
                while(!st.empty() && st.top()>num[i] && k>0)
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
           
           int i=0;
            reverse(ans.begin(),ans.end());
            cout<<ans;
        int j=ans.size();
            while(k>0 && j>=0)
            {
                j--;
                k--;
            }    
            while(ans[i]=='0' && i<ans.size())
                i++;
            if(ans.size()==i)
                return "0";
            return j>=i?ans.substr(i,j-i):"0";
        
    }
};