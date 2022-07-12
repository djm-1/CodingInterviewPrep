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
    int count=0;
    
    void helper(TreeNode *root, int maxi){
        if(root==NULL)
            return;
        
        if(root->val>=maxi)
        {
            maxi=root->val;
            count++;
        }
        helper(root->left,maxi);
        helper(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        helper(root,maxi);
        return count;
    }
};