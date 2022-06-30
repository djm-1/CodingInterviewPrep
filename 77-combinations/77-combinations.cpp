class Solution {
public:
    
    void combination(vector<vector<int>>&ans,vector<int>res,int ind, int k, int n){
        if(k==0)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=ind;i<=n;i++)
        {
            res.push_back(i);
            combination(ans,res,i+1,k-1,n);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>res;
        
        combination(ans,res,1,k,n);
        
        return ans;
    }
};