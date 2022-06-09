class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:t)mp[x]++;
        
        int count=t.size();
        
        int min_len=INT_MAX;
        int min_start=0;
        
        int start=0;
        int end=0;
        while(end<s.size())
        {
            if(mp[s[end]]>0)
                count--;
            mp[s[end]]--;
            end++;
            while(count==0)
            {
                if(end-start<min_len)
                {
                    min_start=start;
                    min_len=end-start; 
                }
                
                    mp[s[start]]++;
                
                if(mp[s[start]]>0)
                    count++;
                start++;
            }
        }
        
        return min_len==INT_MAX?"":s.substr(min_start,min_len);
    }
};