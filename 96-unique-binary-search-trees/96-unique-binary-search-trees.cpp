class Solution {
public:
    vector<int>memo;
    int dp(int n){
        if(n==0||n==1)
            return memo[n]=1;
        if(memo[n]!=-1)
            return memo[n];
        int res=0;
        for(int k=1;k<=n;k++)
            res+=dp(k-1)*dp(n-k);
        return memo[n]=res;
    }
    int numTrees(int n) {
        memo.resize(n+1,-1);
        
        dp(n);
        return memo[n];
    }
};