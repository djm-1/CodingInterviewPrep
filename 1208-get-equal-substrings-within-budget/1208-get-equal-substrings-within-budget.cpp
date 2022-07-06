class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int start=0;
        int sum=0;
        int end=0;
        int maxi=0;
        while(end<n)
        {
            if(sum+abs(s[end]-t[end])<=maxCost)
            {
                sum+=abs(s[end]-t[end]);
                maxi=max(maxi,end-start+1);
                end++;
            }
            else
            {
                sum-=abs(s[start]-t[start]);
                start++;
            }
        }
        
        return maxi;
    }
};