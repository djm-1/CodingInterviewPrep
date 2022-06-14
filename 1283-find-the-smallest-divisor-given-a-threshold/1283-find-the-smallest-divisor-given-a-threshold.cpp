class Solution {
public:
    bool feasible(vector<int>&nums,int threshold,int k){
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=(nums[i]+k-1)/k;
        if(sum<=threshold)
            return true;
        return false;
    }
    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(feasible(nums,threshold,mid)){
                right=mid;
            }
            else
                left=mid+1;
        }
        return left;
    }
};