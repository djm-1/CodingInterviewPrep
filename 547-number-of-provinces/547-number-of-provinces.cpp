class Solution {
public:
    
    void dfs(vector<vector<int>>&Conn, int i, vector<bool>&visited){
        if(visited[i])
            return;
        visited[i]=true;
        for(int k=0;k<visited.size();k++)
        {
            if(Conn[i][k]==1)
                dfs(Conn,k,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& Conn) {
        int n=Conn.size();
        vector<bool>visited(n,false);
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(Conn,i,visited);
                count++;
            }
        }
        
        return count;
    }
};