class Solution {
public:
    int count_setbit(int n){
        int cnt=0;
        while(n!=0){
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++)
        {
            ans[i]=count_setbit(i);
        }

        return ans;

    }
};