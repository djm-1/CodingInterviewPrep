class Solution {
public:
    int mah(int grid[],int n){
        stack<int>st;
        int area=0;
        for(int i=0;i<=n;i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && grid[st.top()]>=grid[i])
                {
                    int idx=st.top();
                    st.pop();
                    if(!st.empty())
                    {
                        area=max(area,grid[idx]*(i-st.top()-1));
                    }
                    else
                    {
                        area=max(area,grid[idx]*i);
                    }
                }
                st.push(i);
            }
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int grid[m+1][n+1];
        memset(grid,0,sizeof(grid));
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i-1][j]=='0')
                    grid[i][j]=0;
                else
                    grid[i][j]=grid[i-1][j]+1;
            }
        }
        
        int max_area=0;
        for(int i=1;i<=m;i++)
        {
            int area=mah(grid[i],n);
            max_area=max(max_area,area);
        }
        return max_area;
    }
};