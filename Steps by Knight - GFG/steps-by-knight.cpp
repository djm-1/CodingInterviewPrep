// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	    // Code here
	    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    // Code here
      vector<pair<int,int>>vec= {{2,1},{-2,-1},{-2,1},{2,-1},{1,-2},{-1,2},{1,2},{-1,-2}};
       queue<pair<int,pair<int, int>>> q;
       vector<vector<int>> visit(N+1, vector<int>(N+1));

       q.push({0,{KnightPos[0],KnightPos[1]}});
       visit[KnightPos[0]][KnightPos[1]]=1;
       while (!q.empty()) {
           int a=q.front().second.first;
           int b=q.front().second.second;
           int ans=q.front().first;
           q.pop();
           for(int i=0; i<vec.size(); i++) {
               int f1=a+vec[i].first;
               int f2=b+vec[i].second;
              if(f1>0 && f1<=N && f2>0 && f2<=N && !visit[f1][f2]) {

                   q.push({ans+1,{f1,f2}});
                   visit[f1][f2]=1;
               }
               if(TargetPos[0]==f1 && TargetPos[1]==f2)
                   return ans+1;
           }

       }

       return 0;

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