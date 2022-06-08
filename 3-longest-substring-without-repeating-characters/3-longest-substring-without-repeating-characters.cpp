class Solution {
public:
    bool checkUnique(unordered_map<char,int>&mp){
        for(auto x:mp)
        {
            if(x.second>1)
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        if(s.size()==0)
            return 0;
        int start=0;
        int max_len=0;
        for(int end=0;end<s.size();end++){
            mp[s[end]]++;
            if(checkUnique(mp))
            {
                max_len=max(max_len,end-start+1);
            }
            else{
                while(!checkUnique(mp))
                {
                    mp[s[start]]--;
                    start++;
                }    
            }
            
        }
        return max_len;
    }
};