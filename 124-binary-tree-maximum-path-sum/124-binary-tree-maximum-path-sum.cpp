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
    int maxi=INT_MIN;
    
    int helper(TreeNode *root){
        if(root==NULL)
            return 0;
        
        int left=helper(root->left);
        int right=helper(root->right);
        
        int res=max(root->val,max(left,right)+root->val);
        maxi=max(max(maxi,left+right+root->val),res);
        return res;
        
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxi;
    }
};