class Solution {
public:
    double binPow(double x, long long n){
        if(n==0) return 1.0;
        if(n==1) return x; //base case
        double halfPow=binPow(x,n/2);
        if(n%2==1){  //n is odd
            return x*halfPow*halfPow;
        }
        else{ // n is even
            return halfPow*halfPow;
        }
    }
    double myPow(double x, long long n) {
        if(n<0){
            double ans=binPow(x,abs(n));
            return 1.0/ans;
        }

        return binPow(x,n);
    }
};