class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int ans;
        
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(edges[0][i]==edges[1][j])
                {
                    ans=edges[0][i];
                    break;
                }
            }
        }
        
        return ans;
    }
};