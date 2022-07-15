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
    
    int helper(TreeNode* root,int val){
        if(root==NULL)
        {    
            return 0;
        }
        
        val=val*10+root->val;
        if(root->left==NULL && root->right==NULL)
            return val;
        return helper(root->left,val)+helper(root->right,val);
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
        
    }
};