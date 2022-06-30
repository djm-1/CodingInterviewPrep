class Solution {
public:
    
    void backtrack(vector<int>&cand,vector<vector<int>>&ans, vector<int>res, int idx, int target){
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=idx;i<cand.size();i++)
        {
            if(i>idx && cand[i]==cand[i-1]) continue;
            if(cand[i]>target) break;
            
            res.push_back(cand[i]);
            backtrack(cand,ans,res,i+1,target-cand[i]);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        sort(candidates.begin(),candidates.end());
        
        backtrack(candidates,ans,res,0,target);
        
        return ans;
        
    }
};