class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        
        vector<vector<pair<double,int>>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        
        priority_queue<pair<double,int>>Q;
        
        vector<double>prob(n,0.00);
        vector<bool>seen(n,false);
        
        Q.push({1.00,start});
        
        prob[start]=1.00;
        
        while(!Q.empty()){
            
            auto v=Q.top();
            Q.pop();
        
            if(!seen[v.second]){
                
                seen[v.second]=true;
                
                for(auto x:adj[v.second])
                {
                    if(x.first*prob[v.second]>prob[x.second])
                    {
                        prob[x.second]=x.first*prob[v.second];
                        Q.push({prob[x.second],x.second});
                    }
                }
            }
        }
        
        return prob[end];
    }
};