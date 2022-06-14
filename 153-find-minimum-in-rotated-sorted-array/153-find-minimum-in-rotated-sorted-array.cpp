class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        //int ans=0;
        int right=n-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[n-1])
            {
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return nums[left];
    }
};