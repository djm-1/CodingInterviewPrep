class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>prefix(n,0);

        prefix[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        // prefix sum calc is done

        for(int i=0;i<n;i++){
            int left=(i>0?prefix[i-1]:0);
            int right=prefix[n-1]-prefix[i];

            if(left==right)
                return i;
        }

        return -1;
    }
};