class Solution {
public:
    bool feasible(vector<int>& candies, long long k, int mid){
        long long int sum=0;
        for(int i=0;i<candies.size();i++)
        {
            sum+=(candies[i]/mid);
        }
        
        if(sum<k)
            return false;
        else
            return true;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int left=1;
        int right=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(feasible(candies,k,mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};