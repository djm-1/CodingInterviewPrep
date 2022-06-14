/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int left=1,right=n;
        int ans=-1;
        while(left<right){
            int mid=left+(right-left)/2;
            int res=guess(mid);
            if(res==-1)
            {
                right=mid-1;
            }
            else if(res==1)
            {
                left=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return left;
    }
};