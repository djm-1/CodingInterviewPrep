class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.size();
        vector<int>ans;
        if(k>s.size())
            return ans;
        vector<int>hash_string(26,0),hash_substring(26,0);
        
        // calc hash of substring
        for(auto x:p)
            hash_substring[x-'a']++;
        
        // calc hash from 0 to k-1;

        for(int i=0;i<k;i++){
            hash_string[s[i]-'a']++;
        }

        // compare
        if(hash_string==hash_substring){
            ans.push_back(0);
        }

        for(int i=k;i<s.size();i++){
            hash_string[s[i]-'a']++;
            hash_string[s[i-k]-'a']--;
            if(hash_string==hash_substring){
                ans.push_back(i-k+1);
            }
        }

        return ans;
    }
};