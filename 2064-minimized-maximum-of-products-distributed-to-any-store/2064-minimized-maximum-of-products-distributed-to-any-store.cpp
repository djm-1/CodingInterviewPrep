class Solution {
public:
    bool feasible(int n,int m,vector<int>&quantities,int maxi){
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=(quantities[i]+maxi-1)/maxi;
        }
        
        if(sum>n)
            return false;
        else
            return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int left=1;
        int right=*max_element(quantities.begin(),quantities.end());
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(feasible(n,m,quantities,mid))
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