class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int x=target-nums[i];
            if(mp[x] && mp[x]!=i)
            {
                res.push_back(i);
                res.push_back(mp[x]);
                break;
            }
        }
        return res;
    }
};