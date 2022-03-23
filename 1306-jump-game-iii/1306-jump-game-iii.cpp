class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>visited(n,false);
        queue<int>Q;
        Q.push(start);
        while(!Q.empty()){
            int v=Q.front();
            visited[v]=true;
            Q.pop();
            if(arr[v]==0)
                return true;
            
            if(v+arr[v]<n && !visited[v+arr[v]])
                Q.push(v+arr[v]);
            if(v-arr[v]>=0 && !visited[v-arr[v]])
                Q.push(v-arr[v]);
        }
        
        return false;
    }
};