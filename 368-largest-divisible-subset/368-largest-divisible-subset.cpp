class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<int>dp(n,1),prev(n);
        
        vector<int>ans;
        
        for(int i=0;i<n;i++)
            prev[i]=i;
        
        int maxi=0;
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            
        }
        
        int lastindex=max_element(dp.begin(),dp.end())-dp.begin();
        //cout<<lastindex;
        while(prev[lastindex]!=lastindex)
        {
            ans.push_back(nums[lastindex]);
            lastindex=prev[lastindex];
        }
        
        ans.push_back(nums[lastindex]);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};