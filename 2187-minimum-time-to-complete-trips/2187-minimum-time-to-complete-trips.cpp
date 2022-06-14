class Solution {
public:
    bool feasible(vector<int>&time, int totalTrips, long long int mid){
        long long int sum=0;
        for(int i=0;i<time.size();i++)
        {
            sum+=mid/(long long int)time[i];
        }
        if(sum<totalTrips)
            return false;
        return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long int left=1;
        long long int right=1e14;
        
        while(left<right)
        {
            long long int mid=left+(right-left)/2;
            if(feasible(time,totalTrips,mid))
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