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
    int index=0;
    TreeNode* construct(vector<int>&postorder,unordered_map<int,int>&mp,int left, int right)
    {
        if(left>right)
            return NULL;
        cout<<index<<"\n";
        int val=postorder[index--];
        int idx=mp[val];
        
        TreeNode *root=new TreeNode(val);
        
        root->right=construct(postorder,mp,idx+1,right);
        root->left=construct(postorder,mp,left,idx-1);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        index=inorder.size()-1;
        //cout<<index<<"\n";
        return construct(postorder,mp,0,inorder.size()-1);
    }
};