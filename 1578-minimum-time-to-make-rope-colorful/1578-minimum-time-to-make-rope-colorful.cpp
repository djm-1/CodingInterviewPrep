class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int max_cost=neededTime[0];
        int sum=neededTime[0];
        
        for(int i=1;i<neededTime.size();i++)
        {
            if(colors[i]!=colors[i-1])
            {
                sum-=max_cost;
                max_cost=0;
            }
            sum+=neededTime[i];
            max_cost=max(max_cost,neededTime[i]);
        }
        
        return sum-max_cost;
    }
};