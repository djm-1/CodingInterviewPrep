class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int cnt = 0, n = nums.size();

        int prefix = 0;

        unordered_map<int, int> mp;

        mp[0] = 1; //empty subarray tracking

        for (int i = 0; i < n; i++) {
            prefix += nums[i];

            if(mp.find(prefix-k)!=mp.end()){
                cnt+=mp[prefix-k];
            }

            mp[prefix]++;
        }

        return cnt;
    }
};