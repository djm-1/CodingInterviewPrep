class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size()>s.size())
            return "";

        // Track frq of t
        unordered_map<char,int>tF,winF;

        for(auto x:t)
            tF[x]++;

        int L=0,R=0,minLen=INT_MAX, startIndex=0;

        int have=0; //no happy customer, all crying
        int need=tF.size(); //How many customers we can make happy by supplying LPG

        for(R=0;R<s.size();R++){
            winF[s[R]]++; //frq up for incoming elements

            if(tF.count(s[R]) && winF[s[R]]==tF[s[R]])
                have++;

            if(have==need){
                while(have==need){
                    // If I find smaller valid window
                    if(R-L+1<minLen){
                        minLen=R-L+1;
                        startIndex=L;
                    }

                    // Shrink the window

                    winF[s[L]]--;
                    
                    // If I lose a happy customer for shrinking window
                    if(tF.count(s[L]) && winF[s[L]]<tF[s[L]])
                        have--;
                    
                    L++;
                }
            }

        }

        if(minLen==INT_MAX)
            return "";
        return s.substr(startIndex,minLen);

    }
};