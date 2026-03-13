class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0,maxLen=0;

        unordered_map<char,int>mp;

        for(r=0;r<n;r++){
            mp[s[r]]++;

            if(mp.size()==(r-l+1)) //if map size==window size
            {
                maxLen=max(maxLen,r-l+1);
            }
            else if(mp.size()<(r-l+1)){
                while(mp.size()<(r-l+1)){
                    mp[s[l]]--;
                    if(mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
                if(mp.size()==(r-l+1)) //if map size==window size
                {
                    maxLen=max(maxLen,r-l+1);
                }
                //maxLen=max(maxLen,r-l+1);
            }
        }

        return maxLen;
    }
};