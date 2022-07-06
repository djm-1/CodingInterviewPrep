class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end(),comp);
        int start=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=intervals[start][1])
            {
                start=i;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};