class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i<s.size();i++){
            if(st.empty()){ //checks stack is empty
                st.push(s[i]);
            }
            else{
                char st_top=st.top(); //stack top

                if((s[i]==')' && st_top=='(') || (s[i]=='}' && st_top=='{')|| (s[i]==']' && st_top=='[')){
                    st.pop(); //pops the top
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