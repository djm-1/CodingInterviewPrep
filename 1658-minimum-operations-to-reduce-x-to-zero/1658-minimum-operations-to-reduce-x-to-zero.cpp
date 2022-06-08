class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(auto num:nums)
            sum+=num;
        if(sum<x)
            return -1;
        sum-=x;
        int max_size=-1;
        int start=0;
        int checksum=0;
        for(int end=0;end<nums.size();end++)
        {
            checksum+=nums[end];
            while(checksum>sum)
            {
                checksum-=nums[start];
                start++;
            }
            if(checksum==sum)
                max_size=max(max_size,end-start+1);
        }
        return max_size==-1?-1:nums.size()-max_size;
    }
};