class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0, r=0, maxSum=INT_MIN, sum=0;

        for(r=0;r<k;r++){
            sum+=nums[r];
        }

        maxSum=max(maxSum,sum);

        for(r=k;r<n;r++){
            sum+=(nums[r]-nums[l]);
            maxSum=max(maxSum,sum);
            l++;
        }


        return (double)maxSum/(double)k;
    }
};