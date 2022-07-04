// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	
	    vector<pair<int,int>> dir={
        {2,1},{-2,-1},{-2,1},{2,-1},{1,-2},{-1,2},{1,2},{-1,-2}
    };
	
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	  
	    vector<vector<bool>>visited(N+2,vector<bool>(N+2,false));
	    
	    queue<pair<int,int>>Q;
	    Q.push({KnightPos[0],KnightPos[1]});
	    visited[KnightPos[0]][KnightPos[1]]=true;
	    int count=0;
	    
	    while(!Q.empty()){
	        int m=Q.size();
	        for(int sz=0;sz<m;sz++)
	        {
    	        pair<int,int>v=Q.front();
    	        Q.pop();
    	        if(v.first==TargetPos[0] && v.second==TargetPos[1])
    	            return count;
    	        for(auto d:dir){
    	            int x=v.first+d.first;
    	            int y=v.second+d.second;
    	            
    	            if(x>=1 && x<=N && y>=1 && y<=N && !visited[x][y])
    	            {
    	                Q.push({x,y});
    	                visited[x][y]=true;
    	            }
    	        }
	        }
	        count++;
	    }
	    
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends