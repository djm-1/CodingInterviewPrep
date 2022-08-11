class Solution {
public:
    
    bool check(vector<int>&nums, int m, int mid)
    {
        int sum=0;
        int cnt=1;
        
        for(auto x:nums)
        {
            if(x>mid)
                return false;
            if(sum+x>mid)
            {
                sum=x;
                cnt++;
            }
            else
            {
                sum+=x;
            }
        }
        
        //cout<<cnt<<"\n";
        if(cnt<=m)
            return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int right=0;
        for(auto x:nums)
            right+=x;
        int left=1;
        if(right==0)
            return 0;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(check(nums,m,mid))
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return left;
    }
};