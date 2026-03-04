class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                char top=st.top();
                if(s[i]==')' && top=='('||s[i]=='}' && top=='{'||s[i]==']' && top=='['){
                    st.pop();
                }
                else{
                   st.push(s[i]); 
                }
            }
        }

        if(st.empty())
            return true;
        return false;
    }
};