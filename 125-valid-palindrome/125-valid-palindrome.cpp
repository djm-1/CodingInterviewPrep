class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(auto x:s)
        {
            if((x>='a' && x<='z')||(x>='0' && x<='9'))
                s1.push_back(x);
            else if(x>='A' && x<='Z')
                s1.push_back((x-'A')+'a');
        }
        
        
        int n=s1.size();
        
        for(int i=0;i<n/2;i++)
        {
            if(s1[i]!=s1[n-1-i])
                return false;
        }
        
        return true;
    }
};