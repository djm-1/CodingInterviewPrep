class Solution {
public:
    bool isVowel(char &c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.size();

        int l=0,r=0,maxLen=0,vowels=0;

        //First Window
        for(r=0;r<k;r++){
            if(isVowel(s[r])){
                vowels++;
            }
        }

        maxLen=max(maxLen,vowels);

        for(r=k;r<n;r++){
            if(isVowel(s[r])){
                vowels++;
            }
            if(isVowel(s[l]))
                vowels--;
            l++;
            maxLen=max(maxLen,vowels);
            
        }

        return maxLen;
    }
};