class Solution {
public:
    bool checkZeroOnes(string s) {
        int max_zero=0,zero=0,one=0,max_one=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                max_one=max(max_one,one);
                one=0;
                zero++;
            }
            else
            {
                max_zero=max(max_zero,zero);
                zero=0;
                one++;
            }
        }
        max_zero=max(max_zero,zero);
        max_one=max(max_one,one);
        return max_one>max_zero;
    }
};