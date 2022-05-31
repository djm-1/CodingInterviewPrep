class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
      
        int cost=0;
        // homepos cost would be included, we can't compare homepos and startpos directly. so starting from home to !start
        
        // seems like a dp/graph problem but actually greedy...beware pls
        for(int i=homePos[0];i!=startPos[0];i+=(i<startPos[0]?1:-1))
            cost+=rowCosts[i];
        for(int i=homePos[1];i!=startPos[1];i+=(i<startPos[1]?1:-1))
            cost+=colCosts[i];
        return cost;
        
    }
};