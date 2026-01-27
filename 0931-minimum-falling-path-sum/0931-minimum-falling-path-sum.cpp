class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=min(
                    matrix[i-1][j],
                    min(
                        j==0?INT_MAX:matrix[i-1][j-1],
                        j==n-1?INT_MAX:matrix[i-1][j+1]
                    )
                )+matrix[i][j];
            }
        }
        
        return *min_element(matrix[m-1].begin(),matrix[m-1].end());
    }
};