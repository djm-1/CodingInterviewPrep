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
    int count=0;
public:
    
    vector<int>helper(TreeNode *root){
        if(root==NULL)
            return {0,0};
        
        vector<int>left=helper(root->left);
        vector<int>right=helper(root->right);
        
        int sum=left[0]+root->val+right[0];
        int subtree=left[1]+1+right[1];
        
        if(sum/subtree==root->val)
            count++;
        return {sum,subtree};
    }
    int averageOfSubtree(TreeNode* root) {
        
        helper(root);
        return count;
    }
};