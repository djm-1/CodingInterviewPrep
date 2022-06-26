class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int start=0,end=0;
        int sum=0;
        for(auto x:card)
            sum+=x;
        int mini=INT_MAX;
        int local=0;
        while(end<n)
        {
            if(end<n-k)
            {
                local+=card[end];
            }
            else
            {
                mini=min(mini,local);
                local-=card[start];
                start++;
                local+=card[end];
            }
            end++;
        }
        
        mini=min(mini,local);
        return sum-=mini;
    }
};