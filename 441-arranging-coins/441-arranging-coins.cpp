typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        ll low=1;
        ll high=n;
        
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            ll curr=(mid*(mid+1))/2;
            if(curr==n)
                return mid;
            else if(curr>n)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return low-1;
    }
};