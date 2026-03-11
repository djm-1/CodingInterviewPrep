class Solution {
public:
    bool ispowTwo(int n){
        return (n>0 && (n&(n-1))==0);
    }
    int setBitIndex(int n){
        int index=(int)log2(n);
        return index;
    }
    bool isPowerOfFour(int n) {
        return ispowTwo(n) && (setBitIndex(n)%2==0);
    }
};