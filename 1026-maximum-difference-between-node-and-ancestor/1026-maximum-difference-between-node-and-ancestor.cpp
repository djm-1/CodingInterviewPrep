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
    int helper(TreeNode *root, int mini, int maxi){
        if(root==NULL)
            return maxi-mini;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        
        int left=helper(root->left,mini,maxi);
        int right=helper(root->right,mini,maxi);
        
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        return helper(root,root->val,root->val);
    }
};