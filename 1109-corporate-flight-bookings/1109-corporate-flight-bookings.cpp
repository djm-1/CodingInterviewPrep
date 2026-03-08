class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n+1,0);

        for(int i=0;i<bookings.size();i++){
            int start=bookings[i][0];
            int end=bookings[i][1];

            ans[start-1]+=bookings[i][2];
            ans[end]-=bookings[i][2];
        }

        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i]+ans[i-1];
        }

        ans.resize(n);
        return ans;
    }
};