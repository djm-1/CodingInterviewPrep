class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int max_len=0;
        int start=0;
        for(int end=0;end<s.size();end++){
            mp[s[end]]++;
            if(mp.size()==end-start+1)
            {
                max_len=max(max_len,end-start+1);
            }
            else if(mp.size()<end-start+1)
            {
                while(mp.size()<end-start+1)
                {
                    mp[s[start]]--;
                    if(mp[s[start]]==0)
                        mp.erase(s[start]);
                    start++;
                }
            }
        }
        return max_len;
    }
};