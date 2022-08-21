class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        
        for(int i=2;i<n;i++)
        {
            int left=0,right=i-1;
            while(left<right){
            if(nums[left]+nums[right]>nums[i])
            {
                count+=right-left;
                right--;
            }
                
            else
            {
                left++;
            }
        }
        }
        
        return count;
    }
};