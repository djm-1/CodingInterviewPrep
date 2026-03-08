class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix=0;
        int cnt=0;

        int n=nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;

        for(int i=0;i<n;i++){
            prefix+=nums[i];
            if(mp[prefix-k]){
                cnt+=mp[prefix-k];
            }
            mp[prefix]++;
        }

        return cnt;
    }
};