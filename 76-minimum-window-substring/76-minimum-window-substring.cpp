class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(auto x:t)
            m[x]++;
        
        int count=m.size();
        int mlen=INT_MAX,mstart=0;
        
        int start=0,end=0;
        while(end<s.size()){
            if(m.find(s[end])!=m.end()){
                m[s[end]]--;
                if(m[s[end]]==0)
                    count--;
            }
            
            end++;
            while(count==0)
            {
                if(end-start<mlen)
                {
                    mlen=end-start;
                    mstart=start;
                }
                
                if(m.find(s[start])!=m.end())
                {
                    m[s[start]]++;
                    if(m[s[start]]==1)
                        count++;
                }
                start++;
                
            }
        }
        return mlen==INT_MAX?"":s.substr(mstart,mlen);
    }
};