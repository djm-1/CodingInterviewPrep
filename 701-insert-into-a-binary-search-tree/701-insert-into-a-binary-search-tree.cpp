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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *temp=root;
        
        if(root==NULL){
            temp=new TreeNode(val);
            return temp;
        }
        
        while(root!=NULL)
        {
            if(val<root->val)
            {
                if(root->left==NULL)
                    break;
                root=root->left;
            }
            else if(val>root->val)
            {
                if(root->right==NULL)
                    break;
                root=root->right;
            }
        }
        
        
        if(val<root->val)
            root->left=new TreeNode(val);
        else
            root->right=new TreeNode(val);
        
        return temp;
    }
};