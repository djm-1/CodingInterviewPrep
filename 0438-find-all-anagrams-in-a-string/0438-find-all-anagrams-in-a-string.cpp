class Solution {
public:
    bool isAnagram(unordered_map<char,int>&mp){
        for(auto x:mp){
            if(x.second!=0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>ans;
        int l=0,r=0;

        int k=p.size(); //window size

        if(n<k) 
            return ans;

        unordered_map<char,int>mp;

        for(auto x:p)
            mp[x]++; //Tracking freq.

        for(r=0;r<k;r++){
            if(mp.find(s[r])!=mp.end()){
                mp[s[r]]--; //req going down for incoming
            }
        } //first window
        
        if(isAnagram(mp))
        {
            ans.push_back(0);
        }

        //after first window is done

        for(r=k;r<n;r++){
            // from l side char going out
            if(mp.find(s[l])!=mp.end()){
                mp[s[l]]++;
            }
            
            l++;

            if(mp.find(s[r])!=mp.end()){
                mp[s[r]]--; //req going down for incoming
            }

            if(isAnagram(mp))
            {
                ans.push_back(l);
            }

            //l++;
        }

        return ans;
    }
};