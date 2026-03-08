class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n),prefix(n);

        prefix[0]=nums[0],suffix[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }

        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }


        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int prefProd=(i==0?1:prefix[i-1]);
            int suffProd=(i==n-1?1:suffix[i+1]);

            ans[i]=suffProd*prefProd;
        }

        return ans;

    }
};