class Solution {
public:
    
    void mergeSort(int l, int r, vector<int>&ans,vector<pair<int,int>>&stor)
    {
        if(l>=r)
            return;
        int mid=(l+r)/2;
        mergeSort(l,mid,ans,stor);
        mergeSort(mid+1,r,ans,stor);
        
        int i=l,j=mid+1,k=0;
        vector<pair<int,int>>v(r-l+1);
        while(i<=mid && j<=r)
        {
            if(stor[j].first<stor[i].first)
            {
                ans[stor[i].second]+=r-j+1;
                v[k++]=stor[i++];
            }
            else
            {
                v[k++]=stor[j++];
            }
        }
        
        while(i<=mid)
            v[k++]=stor[i++];
        while(j<=r)
            v[k++]=stor[j++];
        
        for(k=l;k<=r;k++)
        {
            stor[k]=v[k-l];
        }
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>stor;    
        
        for(int i=0;i<n;i++)
            stor.push_back({nums[i],i});
        
        mergeSort(0,n-1,ans,stor);
        return ans;
    }
};