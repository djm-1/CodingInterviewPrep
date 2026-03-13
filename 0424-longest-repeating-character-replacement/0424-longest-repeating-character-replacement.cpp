class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;

        int l=0,r=0,maxFreq=0;
        for(r=0;r<n;r++){
            mp[s[r]]++;
            maxFreq=max(maxFreq,mp[s[r]]);

            if((r-l+1)-maxFreq>k){
                mp[s[l]]--;
                l++;
            }
        }
        
        return n-l;
    }
};