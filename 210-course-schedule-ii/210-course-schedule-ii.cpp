class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        
        vector<int>indegree(num,0);
        
        vector<vector<int>>adj(num);
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        queue<int>Q;
        
        for(int i=0;i<num;i++)
        {
            if(indegree[i]==0)
                Q.push(i);
        }
        
        vector<int>ans;
        while(!Q.empty()){
            int v=Q.front();
            Q.pop();
            ans.push_back(v);
            
            for(auto x:adj[v])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    Q.push(x);
            }
            
        }
        
        if(ans.size()==num)
            return ans;
        return {};
    }
};