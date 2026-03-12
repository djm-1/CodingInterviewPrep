class Solution {
public:
    bool helper(vector<int>& piles, int mid, int h){
        long long cnt=0;
        for(auto x:piles){
            cnt+=((x+mid-1)/mid);
        }

        if(cnt<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int ans=INT_MAX;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;

            if(helper(piles,mid,h)){ //returns T/F based on if koko can finish eating in h hours while having eating speed=mid
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};