class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        if(n<3)
            return res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            int target=-nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[j]+nums[k];
                if(sum==target)
                {
                    vector<int>triplet{nums[i],nums[j],nums[k]};
                    res.push_back(triplet);
                    
                    while(j<k && triplet[1]==nums[j])
                        j++;
                    while(j<k && triplet[2]==nums[k])
                        k--;
                }
                else if(sum<target){
                    j++;
                }
                else
                    k--;
            }
            
            while(i+1<n && nums[i+1]==nums[i])
                i++;
        }
        
        return res;
    }
};