class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]^arr[i];
        }
        
        vector<int>ans;
        for(auto x:queries)
        {
            if(x[0]==0)
            {
                ans.push_back(prefix[x[1]]);
            }
            else{
                ans.push_back(prefix[x[1]]^prefix[x[0]-1]);
            }
        }
        
        return ans;
    }
};