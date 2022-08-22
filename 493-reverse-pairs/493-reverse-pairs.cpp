class Solution {
public:
    
    int merge(int l,int mid, int r, vector<int>&nums)
    {
        
        int i=l,j=mid+1;
        //vector<int>v;
        int cnt=0;
        while(i<=mid && j<=r)
        {
            if((long long)nums[i]>2LL*(long long)nums[j])
            {
               cnt+=mid-i+1;
               j++;
            }
            else
            {
                i++;
            }
            
        }
        
        sort(nums.begin()+l,nums.begin()+r+1);
        return cnt;
    }
    
    int mergeSort(int i,int j,vector<int>&nums)
    {
        if(i>=j)
            return 0;
        int mid=(i+j)/2;
        int cnt=0;
        cnt+=mergeSort(i,mid,nums);
        cnt+=mergeSort(mid+1,j,nums);
        cnt+=merge(i,mid,j,nums);
        return cnt;
        
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(0,n-1,nums);
        
    }
};