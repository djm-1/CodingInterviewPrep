class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixProd(n),suffixProd(n),ans(n);

        prefixProd[0]=nums[0];
        suffixProd[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefixProd[i]=prefixProd[i-1]*nums[i];
        }

        for(int i=n-2;i>=0;i--){
            suffixProd[i]=suffixProd[i+1]*nums[i];
        }

        for(int i=0;i<n;i++){
            int leftProd=(i==0?1:prefixProd[i-1]);
            int rightProd=(i==n-1?1:suffixProd[i+1]);

            ans[i]=leftProd*rightProd;
        }

        return ans;

    }
};