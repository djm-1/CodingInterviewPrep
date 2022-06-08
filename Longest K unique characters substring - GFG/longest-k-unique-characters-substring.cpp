// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  
  public:
    int checkfreq(vector<int>&frq,int k){
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(frq[i]!=0)
                count++;
        }
        if(count==k)
            return 0;
        else if(count>k)
            return 1;
        else
            return 2;
    }
    int longestKSubstr(string s, int k) {
    // your code here
    vector<int>frq(26,0);
    int max_len=-1;
    int start=0;
    for(int end=0;end<s.size();end++)
    {
        frq[s[end]-'a']++;
        int chk=checkfreq(frq,k);
        if(chk==0)
            max_len=max(max_len,end-start+1);
        else if(chk==1)
            {
                while(checkfreq(frq,k)==1)
                {
                    frq[s[start]-'a']--;
                    start++;
                }
            }
        
    }
    
    return max_len;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends