class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int ast:asteroids){
            bool survive=true;

            while(survive && ast<0 && !st.empty() && st.top()>0){
                if(st.top()< -ast){
                    st.pop();
                }
                else if(st.top()== -ast){
                    st.pop();
                    survive=false;
                }
                else{
                    survive=false;
                }
            }

            if(survive)
                st.push(ast);
        }

        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};