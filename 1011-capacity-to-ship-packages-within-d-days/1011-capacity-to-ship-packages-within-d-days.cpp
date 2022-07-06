class Solution {
public:
    
    bool ispossible(vector<int>&weights, int mid, int days){
        int d=1;
        int wt=0;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]+wt>mid){
                d++;
                wt=weights[i];
            }
            else
                wt+=weights[i];
        }
        
        if(d<=days)
            return true;
        return false;
        
    }
    
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int right=0;
        for(auto x:weights)
            right+=x;
        int left=*max_element(weights.begin(),weights.end());
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(ispossible(weights,mid,days))
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