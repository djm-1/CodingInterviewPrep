// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int start=0,end=0;
	    unordered_map<char,int>m;
	    for(auto x:pat)m[x]++;
	    int count=m.size();
	    int ans=0;
	    int k=pat.size();
	    while(end<txt.size()){
	        m[txt[end]]--;
	        if(m[txt[end]]==0)
	            count--;
	        if(end-start+1<k){
	           end++;
	        }
	        else{
	            if(count==0)
	                ans++;
	            m[txt[start]]++;
	            if(m[txt[start]]==1)
	                count++;
	            
	            start++;
	            end++;
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends