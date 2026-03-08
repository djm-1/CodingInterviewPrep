class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int prefix=0;
        unordered_map<int,int>mp;


        mp[0]=1;

        for(int i=0;i<n;i++){
            prefix+=nums[i]%2;

            if(mp[prefix-k])
                cnt+=mp[prefix-k];

            mp[prefix]++;
        }

        return cnt;
    }
};