class Solution {
public:
 
    bool isPossible(vector<int>&nums, int opr, int val){
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=(nums[i]-1)/val;
        }
        return count<=opr?true:false;
    }
    
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=1e9+7;
        
        while(low<high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,maxOperations,mid))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return low;
    }
};