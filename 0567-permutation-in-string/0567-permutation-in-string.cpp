class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();

        if(m>n)
            return false;
        
        vector<int>hash_string(26,0),hash_substring(26,0);

        for(auto x:s1)
            hash_substring[x-'a']++;
        

        for(int i=0;i<m;i++)
        {
            hash_string[s2[i]-'a']++;
        }

        if(hash_string==hash_substring){
            return true;
        }

        for(int i=m;i<n;i++){
            hash_string[s2[i]-'a']++;
            hash_string[s2[i-m]-'a']--;

            if(hash_string==hash_substring){
            return true;
            }
        }

        return false;
    }
};