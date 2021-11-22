class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        
        int carry=0;
        
        string s;
        
        while(i>=0 || j>=0)
        {
            int sum=(i>=0?a[i]-'0':0)+((j>=0?b[j]-'0':0))+carry;
            s.push_back(sum%2+'0');
            carry=sum/2;
            i--;
            j--;
        }
        if(carry!=0)
            s.push_back('1');
        reverse(s.begin(),s.end());
        return s;
    }
};