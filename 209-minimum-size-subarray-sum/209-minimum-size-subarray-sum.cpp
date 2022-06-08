class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start=0;
        int sum=0;
        int min_len=INT_MAX;
        for(int end=0;end<nums.size();end++){
            sum+=nums[end];
            while(sum>=target){
                min_len=min(min_len,end-start+1);
                sum-=nums[start];
                start++;
            }
        }
        return min_len==INT_MAX?0:min_len;
    }
};