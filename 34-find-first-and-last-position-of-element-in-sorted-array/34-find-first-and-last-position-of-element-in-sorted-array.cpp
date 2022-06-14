class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        if(nums.size()==0)
            return ans;
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        if(nums[left]==target)
            ans[0]=left;
        
        left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2+1;
            if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid;
            }
            
        }
        if(nums[right]==target)
            ans[1]=right;
        return ans;
    }
};