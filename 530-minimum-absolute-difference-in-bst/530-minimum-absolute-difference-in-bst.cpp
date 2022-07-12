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
    int mindiff=INT_MAX;
    int prev=-1;
    void helper(TreeNode *curr){
        if(curr==NULL)
            return;
        helper(curr->left);
        if(prev!=-1){
            mindiff=min(mindiff,abs(curr->val-prev));
        }
        prev=curr->val;
        helper(curr->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return mindiff;
    }
};