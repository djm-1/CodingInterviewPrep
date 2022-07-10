class Solution {
public:
    typedef pair<int,pair<int,int>>pi;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({matrix[i][0],{i,0}});
        }
        
        while(--k && !pq.empty()){
            
            auto x=pq.top().second;
            pq.pop();
            int i=x.first;
            int j=x.second;
            
            if(j<n-1)
            {
                pq.push({matrix[i][j+1],{i,j+1}});
            }
        }
        
        return pq.top().first;
        
    }
};