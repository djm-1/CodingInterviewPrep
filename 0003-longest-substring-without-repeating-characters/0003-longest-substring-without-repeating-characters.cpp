class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        unordered_map<char,int>mp;
        int n=s.size();
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            j++;
            if(mp.size()==j-i)
            {
                maxLen=max(maxLen,j-i);
            }
            else{
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }

        return maxLen;
    }
};