class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0,left=0,right=0,down=0;
        for(int x:moves){
            if(x=='U')
                up++;
            if(x=='D')
                down++;
            if(x=='L')
                left++;
            if(x=='R')
                right++;
        }
        
        if(left==right && up==down)
            return true;
        return false; 
    }
};