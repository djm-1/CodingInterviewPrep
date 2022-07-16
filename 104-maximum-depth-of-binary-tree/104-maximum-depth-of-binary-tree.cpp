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
    int maxi=0;
    void helper(TreeNode *root, int depth)
    {
        if(root==NULL)
            return;
        maxi=max(maxi,depth);
        helper(root->left,depth+1);
        helper(root->right,depth+1);
    }
    int maxDepth(TreeNode* root) {
        helper(root,1);
        return maxi;
    }
};