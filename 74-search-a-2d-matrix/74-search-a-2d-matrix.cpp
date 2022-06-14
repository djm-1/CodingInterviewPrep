class Solution {
public:
    int rowsearch(vector<vector<int>>& matrix, int target){
        int ans=-1;
        int m=matrix.size();
        
        int left=0,right=m;
        while(left<right){
            int mid=(left+right)/2;
            if(matrix[mid][0]<=target){
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return ans;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=rowsearch(matrix,target);
        //cout<<row;
        if(row==-1)
            return false;
        else{
            int n=matrix[0].size();
            int left=0,right=n;
            while(left<right)
            {
                int mid=(left+right)/2;
                if(matrix[row][mid]==target)
                    return true;
                else if(matrix[row][mid]<target){
                    left=mid+1;
                }
                else
                {
                    right=mid;
                }
            }
            
            return false;
        }
    }
};