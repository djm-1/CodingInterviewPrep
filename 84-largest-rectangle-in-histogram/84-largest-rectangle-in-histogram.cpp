class Solution {
public:
    void NSL(vector<int>&heights, vector<int>&nsl,int n){
        
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()]>heights[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    nsl[i]=st.top();
                }
                st.push(i);
            }
        }
        return;
    }
    
    
    void NSR(vector<int>&heights, vector<int>&nsr,int n){
        
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()]>heights[i])
                {
                    nsr[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        
        return;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int>nsl(n,-1),nsr(n,n);
        int hist=0;
        NSL(heights,nsl,n);
        NSR(heights,nsr,n);
        for(int i=0;i<n;i++)
        {
            int area=(nsr[i]-nsl[i]-1)*heights[i];
            hist=max(area,hist);
        }
        return hist;
    }
};