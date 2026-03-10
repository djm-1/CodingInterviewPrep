class Solution {
public:
    
    double calc(double x,int n){
        if(n==0)
            return 1;
        else if(n%2==0)
            return calc(x*x,n/2);
        else
            return x*calc(x*x,n/2);
    }
    
    double myPow(double x, int n) {
        if(n<0)
        {
            n=abs(n);
            x=1/x;
        }
        return calc(x,n);
    }
};