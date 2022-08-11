class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        for(auto x:nums)
            s.insert(x);
        if(nums.size()>s.size())
            return true;
        return false;
    }
};