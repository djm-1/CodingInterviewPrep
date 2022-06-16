class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int area=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    int idx=st.top();
                    st.pop();
                    if(!st.empty())
                        area=max(area,heights[idx]*(i-st.top()-1));
                    else
                        area=max(area,heights[idx]*i);
                }
                st.push(i);
            }
        }
        return area;
    }
};