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
    vector<int>arr;
    
    void inorder(TreeNode *root){
        if(root==NULL)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            if(arr[i]+arr[j]==k)
                return true;
            if(arr[i]+arr[j]<k)
                i++;
            else
                j--;
        }
        return false;
    }
};