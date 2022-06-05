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
    void inorder(TreeNode* root, vector<int>&nodes){
        if(root==NULL)
            return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>nodes;
        inorder(root,nodes);
        TreeNode* new_root=new TreeNode(nodes[0]);
        TreeNode* temp=new_root;
        for(int i=1;i<nodes.size();i++)
        {
            temp->right=new TreeNode(nodes[i]);
            temp=temp->right;
        }
        return new_root;
    }
};