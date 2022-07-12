/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(int s, int e, vector<int>&nums){
        if(s>=e)
            return NULL;
        int mid=(s+e)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=helper(s,mid,nums);
        node->right=helper(mid+1,e,nums);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0,nums.size(),nums);
    }
};