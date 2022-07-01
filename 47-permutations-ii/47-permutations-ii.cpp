class Solution {
public:
    
    void permute(vector<int>&nums, int idx, vector<vector<int>>&ans){
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int>s;
        for(int i=idx;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
            swap(nums[i],nums[idx]);
            permute(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        permute(nums,0,ans);
        
        return ans;
        
    }
};