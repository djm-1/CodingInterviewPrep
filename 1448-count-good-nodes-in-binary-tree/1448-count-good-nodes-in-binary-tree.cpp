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
    void inorder(TreeNode* root, int maxi){
        if(root==NULL)
            return;
        
        if(root->val>=maxi)
        {
            count++;
            maxi=root->val;
        }
        inorder(root->left,maxi);
        inorder(root->right,maxi);
        //return;
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        
        inorder(root,INT_MIN);
        return count;
    }
};