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
    int sum=0;
    
    void helper(TreeNode* root, int val)
    {
        if(root==NULL)
            return;
        
        
        val=2*val+root->val;
        if(!root->right && !root->left)
        {
            sum+=val;
            return;
        }
        helper(root->left,val);
        helper(root->right,val);
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0);
        return sum;
    }
};