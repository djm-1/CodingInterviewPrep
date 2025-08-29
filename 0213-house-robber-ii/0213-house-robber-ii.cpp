class Solution {
public:
    int houseRobber(vector<int>& arr){
        int n=arr.size();
        vector<int>dp(n+1,0);

        dp[0]=0;
        dp[1]=arr[0];

        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-2]+arr[i-1],dp[i-1]);
        }

        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>temp1(n-1),temp2(n-1);
        for(int i=0;i<n;i++){
            if(i==0){
                temp1.push_back(nums[i]);
            }
            else if(i==n-1){
                temp2.push_back(nums[i]);
            }
            else{
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
        }

        return max(houseRobber(temp1),houseRobber(temp2));
    }
};