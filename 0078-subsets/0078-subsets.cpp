class Solution {
public:

void solve(vector<int>&nums, int i, vector<int>&curr, vector<vector<int>>&ans){
        int n=nums.size();
        if(i==n){
            ans.push_back(curr);
            return;
        } //base case

        //1,2,3 curr=[1]
        //  |
//including
        curr.push_back(nums[i]);  //curr=[1,2]
                                // 1,2,3,4,5
                                //     |
        solve(nums,i+1,curr,ans);

        //curr=[1,2] -> curr=[1]
//excluding
        curr.pop_back();      // 1,2,3,4,5
                                //   |

        solve(nums,i+1,curr,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;  //[[],[1],[2],[1,2],....
        vector<int>curr; //[1,2,3] [1,2]
        solve(nums,0,curr,ans);

        return ans;
    }
};