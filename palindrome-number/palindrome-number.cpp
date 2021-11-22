class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0)
            return true;
        else{
            string arr=to_string(x);
            int n=arr.size();
            for(int i=0;i<n/2;i++)
            {
                if(arr[i]!=arr[n-1-i])
                    return false;
            }
            return true;
        }
    }
};