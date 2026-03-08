class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;

        mp[0]=1;
        
        int prefix=0;

        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int rem=((prefix%k)+k)%k;

            count+=mp[rem];
            mp[rem]++;

        }

        return count;

    }
};