class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x]++;
        for(auto x:mp)
            if(x.second%2==1)
                return false;
        return true;
    }
};