class Solution {
public:
    
    void backtrack(vector<vector<int>>&graph, int s, int d, vector<vector<int>>&ans, vector<int>&res){
      
        res.push_back(s);
        if(s==d){
            ans.push_back(res);
        }
        else
        {
            for(auto x:graph[s])
                backtrack(graph,x,d,ans,res);
        }
        res.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>ans;
        vector<int>res;
        int n=graph.size();
        
        backtrack(graph,0,n-1,ans,res);
        
        return ans;
        
    }
};