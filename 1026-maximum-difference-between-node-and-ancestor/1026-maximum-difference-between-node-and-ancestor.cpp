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
    int maxdiff=INT_MIN;
    void helper(TreeNode *root, int mini, int maxi){
        if(root==NULL)
            return;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        
        maxdiff=max(maxdiff,maxi-mini);
        
        helper(root->left,mini,maxi);
        helper(root->right,mini,maxi);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return maxdiff;
    }
};