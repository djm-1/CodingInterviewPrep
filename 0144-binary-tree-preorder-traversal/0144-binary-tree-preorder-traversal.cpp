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
    void helper(TreeNode* root, vector<int>&TreeValue){
        if(root==NULL)
            return; //Base condition
        TreeValue.push_back(root->val); //process node
        helper(root->left,TreeValue); //visit Left
        helper(root->right,TreeValue);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>TreeValue;
        helper(root,TreeValue); //Recursive function
        return TreeValue;
    }
};