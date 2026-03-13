class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        int l=0, r=0, oddCount=0, ans=0,cnt=0;

        for(r=0;r<n;r++){
            if(nums[r]%2==1){
              oddCount++;
              cnt=0;
            } //incoming=odd

            while(oddCount==k){
                cnt++;
                if(nums[l]%2==1)
                    oddCount--;

                l++;   //outgoing=odd
            }

            ans+=cnt;
        }

        return ans;
    }
};