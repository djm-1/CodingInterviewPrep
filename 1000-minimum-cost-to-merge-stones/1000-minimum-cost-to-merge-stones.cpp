class Solution {
public:
    vector<int>prefix;

    int dp[31][31];

    int solve(int i, int j, int k){
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans=INT_MAX;

        for(int m=i;m<j;m+=(k-1)){
            ans=min(ans, solve(i,m,k)+solve(m+1,j,k));
        }

        if((j-i)%(k-1)==0) //valid
        {
            ans+=prefix[j+1]-prefix[i]; //cost for range sum
        }

        return dp[i][j]=ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        // Think of approach for 10 mins. Then I'll ask you   

        // (3,2) (4,1) -> 5+5

        //     (5, 5) -> 10

        // (3 ,2 ,4), 1, 10     k=3

        // 9 ,1, 10

        int n=stones.size();
        if((n-1)%(k-1)!=0)
            return -1;

        prefix.resize(n+1,0);
        memset(dp,-1,sizeof(dp));

        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+stones[i-1];
        }

        return solve(0,n-1,k);
        
    }
};