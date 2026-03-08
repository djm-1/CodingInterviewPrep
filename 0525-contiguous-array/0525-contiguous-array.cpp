class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==0)
                nums[i]=-1;
        }

        int maxLen=0,prefix=0;

        unordered_map<int,int>mp;

        mp[0]=-1;

        for(int i=0;i<n;i++){
            prefix+=nums[i];
            if(mp.find(prefix)!=mp.end()){
                maxLen=max(maxLen,i-mp[prefix]);
            }
            else{
                mp[prefix]=i;
            }
        }

        return maxLen;
    }
};