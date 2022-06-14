class Solution {
public:
    bool feasible(vector<int>&piles, int h, int speed)
    {
        int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            sum+=(piles[i]+speed-1)/speed;
        }
        if(sum<=h)
            return true;
        else
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(feasible(piles,h,mid))
            {
                right=mid;
            }
            else
                left=mid+1;
        }
        return left;
    }
};