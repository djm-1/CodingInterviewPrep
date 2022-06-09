class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m;
        for(auto x:s1)m[x]++;
        int count=m.size();
        int k=s1.size();
        int start=0,end=0;
        while(end<s2.size()){
            if(m.find(s2[end])!=m.end())
            {
                m[s2[end]]--;
                if(m[s2[end]]==0)
                    count--;
            }
            
            if(end-start+1==k)
            {
                if(count==0)
                    return true;
                if(m.find(s2[start])!=m.end())
                {
                    m[s2[start]]++;
                    if(m[s2[start]]==1)
                        count++;
                }
                start++;
            }
            end++;
        }
        return false;
    }
};