// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool checkAnagram(vector<int>&freq1,vector<int>&freq2){
        bool check=true;
	    for(int i=0;i<26;i++)
	    {
	        if(freq1[i]!=freq2[i])
	        {
	            check=false;
	            break;
	        }
	    }
	    return check;
    }
	int search(string pat, string txt) {
	    // code here
	    vector<int>freq1(26,0),freq2(26,0);
	    for(auto x:pat)
	        freq1[x-'a']++;
	    int count=0;
	    for(int i=0;i<pat.size();i++)
	    {
	        freq2[txt[i]-'a']++;
	    }
	    
	    if(checkAnagram(freq1,freq2))
	        count++;
	    int start=0;
	   for(int end=pat.size();end<txt.size();end++)
	   {
	       freq2[txt[start]-'a']--;
	       freq2[txt[end]-'a']++;
	       if(checkAnagram(freq1,freq2))
	        count++;
	   start++;
	   }
	    return count;    
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