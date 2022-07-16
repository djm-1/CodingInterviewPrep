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
    unordered_map<TreeNode*,int>depth;
    
    int findDepth(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        if(!depth[root])
            depth[root]=max(findDepth(root->left),findDepth(root->right))+1;
        return depth[root];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL)
            return NULL;
        int left=findDepth(root->left);
        int right=findDepth(root->right);
        
        if(left<right)
            return lcaDeepestLeaves(root->right);
        else if(left>right)
            return lcaDeepestLeaves(root->left);
        return root;
    }
};