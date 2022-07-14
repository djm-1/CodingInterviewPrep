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
    int num=0;
    TreeNode* constructTree(vector<int>&preorder, unordered_map<int,int>&index,int left,int right)
    {
        if(left>right)
            return NULL;
        
        int val=preorder[num++];
        int idx=index[val];
        
        TreeNode *root=new TreeNode(val);
        
        root->left=constructTree(preorder,index,left,idx-1);
        root->right=constructTree(preorder,index,idx+1,right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>index;
        for(int i=0;i<inorder.size();i++)
        {
            index[inorder[i]]=i;
        }
        
        return constructTree(preorder,index,0,inorder.size()-1);
    }
};