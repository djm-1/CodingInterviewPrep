class Solution {
public:
    
    void backtrack(vector<int>&candidates, int index, int target, int n, vector<vector<int>>&ans, vector<int>&res){
        
        if(index==n)
        {
            if(target==0)
            {
                ans.push_back(res);
            }
            return;
        }
        
        if(candidates[index]<=target){
            res.push_back(candidates[index]);
            backtrack(candidates,index,target-candidates[index],n,ans,res);
            res.pop_back();
        }
        
        backtrack(candidates,index+1,target,n,ans,res);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        int n=candidates.size();
        
        backtrack(candidates,0,target,n,ans,res);
        
        return ans;
    }
};