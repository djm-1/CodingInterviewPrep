class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int max_profit=0;
        
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            max_profit=max(max_profit,prices[i]-mini);
        }
        
        return max_profit;
    } 
};