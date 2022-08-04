class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>>mp;
      vector<vector<string>>ans;
        
        for(auto x:strs)
        {
            string t=x;
            sort(t.begin(),t.end());
            
            mp[t].push_back(x);
        }
        
        for(auto x:mp)
        {
            vector<string>res;
            for(auto y:x.second)
            {
                res.push_back(y);
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};