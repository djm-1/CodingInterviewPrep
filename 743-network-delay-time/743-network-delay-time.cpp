class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        
        vector<int>dist(n+1,INT_MAX);
        
        dist[k]=0;
        priority_queue<pair<int,int>>Q;
        Q.push({0,k});
        
        while(!Q.empty()){
            auto v=Q.top();
            Q.pop();
            for(auto x:adj[v.second]){
                if(dist[v.second]+x.first<dist[x.second])
                {
                    dist[x.second]=dist[v.second]+x.first;
                    Q.push({dist[x.second],x.second});
                }
            }
        }
        
        int maxi=0;
       
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            maxi=max(maxi,dist[i]);
        }
        
        return maxi;
    }
};